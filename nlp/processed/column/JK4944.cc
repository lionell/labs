#include <stdio.h>

struct droprec {
    int dindex;
    int height;
    long long int volume;
    int todown;
    droprec *prev;
};

droprec *pool;
droprec *makenewrec();
void     droprecord(droprec *rec);


int main(int argc, char **argv)
{
    int N;
    scanf("%d",&N);
    
    int i;
    droprec *temp;
    droprec *lastrec;
    pool=NULL;
    
    int mh=0;
    int cc=0, c1=0, c2=0;
    lastrec=makenewrec();
    lastrec->dindex=0;
    lastrec->height=0;
    lastrec->prev=NULL;
    lastrec->volume=0;
    lastrec->todown=0;
    
    for(i=0;i<=N;i++){
        if(mh<c1){
            mh=c1;
        }
        c2=c1;
        c1=cc;
        if(i==N){
            cc=0;
        }else{

            scanf("%d",&cc);

        }

        if(c1>mh && c2<mh){
            while(lastrec->prev){
                temp=lastrec;
                if(lastrec->height==mh){
                    break;
                }
                lastrec=lastrec->prev;
                droprecord(temp);
            }
            lastrec->todown=0;
        }

        if(c1>c2 && c1<=mh){
            if(lastrec->height){

                while(lastrec->prev){
                    if(lastrec->height>=c1){
                        break;
                    }
                temp=lastrec;
                lastrec=lastrec->prev;
                droprecord(temp);
                }
                if(lastrec->height==c1){
                    lastrec->todown=0;
                    lastrec->dindex=i;
                }else{
                temp=makenewrec();
                temp->todown=0;
                temp->dindex=i;
                temp->height=c1;
                temp->volume=lastrec->volume - (i-1-lastrec->dindex) * (lastrec->height - c1);
                temp->prev=lastrec;
                lastrec=temp;
                }
            }
        }
        if(c1>cc){
            temp=makenewrec();
            temp->prev=lastrec;
            lastrec=temp;
            lastrec->dindex=i;
            lastrec->volume=0;
            lastrec->height=c1;
            lastrec->todown=1;
        }
        temp=lastrec;
        while(temp->prev){
            if(temp->todown){
                temp->volume+=temp->height-c1;
            }
            if(temp->height==mh){
                break;
            }
            temp=temp->prev;
        }
    }
    

    long long int sum=0;
    temp=lastrec;
    while(temp->prev){
        if(!temp->todown){
            sum+=temp->volume;
        }
        temp=temp->prev;
    }
    
    printf("%lli\n",sum);

    while(lastrec){
        temp=lastrec;
        lastrec=lastrec->prev;
        delete temp;
    }
    while(pool){
        temp=pool;
        pool=pool->prev;
        delete temp;
    }

	return 0;
}

droprec *makenewrec()
{
    droprec *tmp;
    if(pool){
        tmp=pool;
        pool=pool->prev;
    }else{
        tmp=new droprec;
    }
    return tmp;
}

void     droprecord(droprec *rec)
{
    rec->prev=pool;
    pool=rec;
}

