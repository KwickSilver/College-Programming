#include<bits/stdc++.h>

struct node {
	int file_name;
	int data;
	int is_free;
	int size;
	int directory;
	int cnt;
	struct node* link;
	struct node* inner_link[30];
};


struct node* defaultFile() {
	struct node* temp = (struct node*)malloc( sizeof(struct node) );
	temp->link = NULL;
	temp->is_free=0;
	temp->data='a';
	temp->file_name=99;
	temp->directory = 1;
	return temp;
}

struct node* insert(struct node *rt, int size, int fname) {
	struct node* temp = rt;
	struct node* first=NULL,*last=NULL,*tt=NULL;
	int flag=0,act_size=0, inner_fname=100,cnt=0;
	last=first;
	act_size = size;
	if ( size>temp->size ) {
		printf("There is not enough space on the disk to write that file\n");
		return rt;
	}
	while( temp->link ) {
		temp = temp->link;
	}
	first = defaultFile();
	while( act_size>0 ) {
		tt = defaultFile();
		if (act_size>50)
		tt->size = 50;
		else
		tt->size = act_size;
		tt->file_name = inner_fname;
		first->inner_link[cnt] = tt;
		tt->directory = 0;
		tt->is_free = 0;
		act_size -= 50;
		inner_fname += 1;
		cnt += 1;
	}
	temp->link = first;
	first->is_free = 1;
	first->cnt = cnt;
	first->size = size;
	first->file_name = fname;
	act_size = rt->size;
	rt->size = act_size-size;
	return rt;
}

void printFiles(struct node* rt) {
	struct node *temp = rt, *tt;
	int first=0,cnt=0;
	printf("format is (File name, size)\n");
	printf("\t(%d,%d)\n",rt->file_name,rt->size);
	while( temp ) {
		if ( temp->is_free ) {
			printf("\t(%d,%d)\n",temp->file_name,temp->size);
			first = 0;
			while( cnt ) {
				tt = temp->inner_link[cnt];
				printf("\t\t(%d,%d)\n",tt->file_name, tt->size);
				cnt += 1;
			}
			printf("\n");
		}
		temp = temp->link;
	}
}

struct node* combine(struct node *rt,int fname) {
	struct node *temp=rt,*nt=NULL,*temp1=temp->link;
	int size=0;
	if ( rt->file_name==fname ){
		printf("You cannot that file as thats just to show that that much amount of space is left in the disk\n");
		return rt;
	}
	while( temp1 ) {
		if (temp1->is_free==0 && temp1->file_name==fname ) {
			size = temp1->size;
			temp->link = temp1->link;
			temp1 = temp->link;
		}
		else {
			temp = temp1;
			temp1 = temp1->link;
		}
	}
	rt->size += size;
	return rt;
}

struct node* deleteFiles(struct node* rt, int fname) {
	struct node *temp = rt,*nt=NULL;
	int flag=0;
	while( temp && flag==0 ) {
		if (temp->file_name==fname) {
			temp->is_free=0;
			flag=1;
		}
		temp = temp->link;
	}
	if( flag==0 ){
		printf("There doesnt exist any file with that name\n");
	}
	return combine(rt,fname);
}

int main() {
	int flag,no,size,data;
	struct node *root;
	root = defaultFile();
	root->size=1000;
	data=100;
	flag=no=size=0;
	while( flag==0 ) {
		printf("Enter no's \n1.insert\n 2.Delete\n 3.Print files \n 4.Exit\n");
		scanf("%d",&no);
		printf(" no is %d\n",no);
		switch(no) {
			case 1:
				printf("Enter file size\n");
				scanf("%d",&size);
				root = insert(root, size, data);
				data = data+1;
				break;
			case 2:
				printf("Enter file name to delete\n");
				scanf("%d",&size);
				root = deleteFiles(root, size);
				break;
			case 3:
				printFiles(root);
				break;
			case 4:
				flag=1;
				printf("Quitting from loop\n");
				break;
			default:
				printf("Enter a valid no \n");
				break;
		}
	}
}

