#include <iostream>

using namespace std;
struct node
{
    int data;
    node *lift;
    node *right;
};
bool found(node*t,int num);
void delete_node();
int num_node_ancestor(node*t,int num);
void inorder(node*t);
void preorder(node*t);
void postorder(node*t);
void inse();
int leafcount(node*t);
int num_node(node*t);
int d;
node *root=NULL,*p,*c,*l;
int main()
{
    int m;
    while(1)
    {
        cout<<"\n***Operation Binary Search Tree ***\n";
        cout<<"\n1-insert \n2-print\n3-number leaves\n4-number node \n5-search";
        cout<<"\n6-number_ancestor\n7-delete_node\n8-delete_tree\n9-exit\n";
        cout<<"Enter choice  "<<endl;
        cin >>m;
        if(m==1)
        {
            inse();
        }
        if(m==2)
        {
            if(root!=NULL)
            {
                cout<<"\n inorder tree is : ";
                inorder(root);
                cout<<"\n preorder tree is : ";
                preorder(root);
                cout<<"\n postorder tree is : ";
                postorder(root);
            }
            else
            {
                cout<<"Tree Is Empty :\n";
            }
        }
        if(m==3)
        {
            int num;
            num=leafcount(root);

            cout<<"number leaves in tree is : "<<num<<endl;

        }
        if(m==4)
            {
                int n;
            n=num_node(root);
        cout<<"number all node in tree is : "<<n<<endl;
            }
        if(m==5)
        {
            cout<<"enter number that you need to search it in tree :\n" ;
            int b;
            bool f;
            cin>>b;
            f=found(root,b);
            if(f)
                cout<<"number found in tree \n";
            else
                cout<<"number not found in tree \n";
        }
        if(m==6)
        {
            cout<<"enter number that you need number ancestor for it : ";
            int nu,l;
            cin>>nu;
            l=num_node_ancestor(root,nu);
            if(l<0)
            {
                cout<<" number that you enter NOT FOUND in tree \n";
            }
            else
            {
                cout<<"number ancestor in tree is : "<<l<<endl;
            }
        }

        if(m==7)
        {

            delete_node();
        }
        if(m==8)
        {
            root=NULL;
        }
        if(m==9)
        {
            return 0;
        }
        if(m>9||m<1){
            cout<<"invalid choice\n";
        }

    }

}

void inorder(node*t)
{
    if(t!=NULL)
    {
        inorder(t->lift);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}
void preorder(node*t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        preorder(t->lift);
        preorder(t->right);
    }
}
void postorder(node*t)
{
    if(t!=NULL)
    {
        postorder(t->lift);
        postorder(t->right);
        cout<<t->data<<" ";
    }
}
void inse( )
{
    p=new node;
    cout<<"Enter data of new node :";
    cin>>d;
    p->data=d;
    p->lift=NULL;
    p->right=NULL;
    if(root==NULL)
    {
        root=p;
    }
    else
    {
        c=root;
        while((c!=NULL))
        {
            if(d>c->data)
            {
                l=c;
                c=c->right;
            }
            else if(d<c->data)
            {
                l=c;
                c=c->lift;
            }
            else
            {
                cout<< "number found in tree enter another number : ";
                cin>>d;
                p->data=d;
                c=root;
                l=NULL;
            }

        }
        if(d>l->data)
        {
            l->right=p;
        }
        else
        {
            l->lift=p;
        }
    }
}
int leafcount(node*t)
{

    if(t==NULL)
    {
        return 0;
    }
    else if((t->lift==NULL)&(t->right==NULL))
    {
        return 1;
    }
    else
        return leafcount(t->lift)+leafcount(t->right);
}
int num_node(node*t)
{
    if(t==NULL)
    {
        return 0;
    }
    else
        return num_node(t->lift)+num_node(t->right)+1;
}
int num_node_ancestor(node*t,int num)
{
    if((num!=t->data) &((t->lift==NULL)&(t->right==NULL)))
    {
        return -9999 ;
    }
    else if(t->data>num)
    {
        return num_node_ancestor(t->lift,num)+1 ;
    }
    else if(t->data<num)
    {
        return num_node_ancestor(t->right,num)+1;
    }
    else
        return 0;
}
void delete_node()
{
    node *pre,*cur,*par;
    if (root==NULL)
    {
        cout<<"Tree Is Empty \n";
    }
    else
    {
        cout<<"enter number that you need to delete from tree : ";
        int n;
        cin>>n;
        cur=pre=root;
        while(cur!=NULL) //search about node that have n
        {
            if(cur->data>n)
            {
                pre=cur;
                cur=cur->lift;
            }
            else if(cur->data<n)
            {
                pre=cur;
                cur=cur->right;
            }
            else
            {
                if(cur->data==n)
                {
                    //delete leaf node no have child
                    if((cur->lift==NULL)&(cur->right==NULL))
                    {
                        if(cur==root)
                        {
                            delete(root);
                            root=NULL;
                        }
                        if(pre->lift==cur)
                        {
                            pre->lift=NULL;
                        }
                        else
                        {
                            pre->right=NULL;
                        }
                        delete(cur);
                        cout<<"delete successful \n";
                        cur=NULL;
                    }
                    //delete node have on child
                    else if(cur->lift==NULL||cur->right==NULL)
                    {
                        if(cur->lift==NULL)  //child found in right
                        {
                            if(cur==root)
                            {
                                root=cur->right;
                            }
                            if(pre->lift==cur)
                            {
                                pre->lift=cur->right;
                            }
                            else
                            {
                                pre->right=cur->right;
                            }
                        }
                        else
                        {
                            if(cur==root)
                            {
                                root=cur->right;
                            }         //child found in lift
                            if(pre->lift==cur)
                            {
                                pre->lift=cur->lift;
                            }
                            else
                            {
                                pre->right=cur->lift;
                            }

                        }
                        delete(cur);
                        cout<<"delete successful \n";
                        cur=NULL;
                    }
                    else if((cur->lift!=NULL)&(cur->right!=NULL)) //delete node have two child
                    {
                        par=cur->right;
                        pre=par;
                        while(par->lift!=NULL)
                        {
                            pre=par;
                            par=par->lift;
                        }
                        if(pre==par) //delete root of tree and right sub tree not have node in left
                        {
                            pre=pre->right;
                        }
                        else
                        {
                            pre->lift=NULL;
                        }
                        cur->data=par->data;
                        cur->right=pre;
                        cur=NULL;
                        delete(par);
                        cout<<"delete successful \n";

                    }
                }
                else
                {
                    cout<<"number not found in tree \n";
                }
            }
        }

    }


}



bool found(node*t,int num)
{
    if(t==NULL)
        return false ;
    else if (t->data>num)
        return found(t->lift,num);
    else if(t->data<num)
        return found(t->right,num);
    else if(t->data==num)
        return true;
    else
        return false ;
}
