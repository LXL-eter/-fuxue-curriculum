//糖：
#include<stdio.h>
#include<math.h>
int main(){
    char s[1001];
    int flag=0,i=0;
    while(1){
        scanf("%c",&s[i]);
        i++;
        if(s[i-1]=='\\')flag=1;
        if(flag==1&&s[i-1]=='\n')break;
    }
    for(int j=0;j<i;j++){
        if(s[j]>='a'&&s[j]<='z')printf("%c",s[j]-32);
        else if(s[j]>='A'&&s[j]<='Z')printf("%c",s[j]+32);
        else if((s[j]>='0'&&s[j]<='9')||s[j]==' '||s[j]=='\n'||s[j]=='\\')printf("%c",s[j]);
         if(s[j]=='\\')break;
    }
}


//泉山顶云,比较日期：
#include<stdio.h>
struct da{
    int x,y,z;
};
int main(){
    int o,p,q,n,cnt=0;
    scanf("%d-%d-%d",&o,&p,&q);
    scanf("%d",&n);
    struct da s[n];
    struct da li={3000,32,32};
    for(int i=0;i<n;i++){
        scanf("%d-%2d-%2d",&s[i].x,&s[i].y,&s[i].z);
        if(o-s[i].x>=3)cnt++;
        else if(o-s[i].x==2){
            if(p-s[i].y>=7)cnt++;
            else if(p-s[i].y==6){
                if(s[i].z<q){cnt++;}
                }
        }
        if(li.x>s[i].x)li=s[i];
        else if(li.x==s[i].x){
            if(li.y>s[i].y)li=s[i];
            else if(li.y==s[i].y){if(li.z>s[i].z)li=s[i];}
        }
    }
    printf("%d\n%d-%02d-%02d",cnt,li.x,li.y,li.z);
}


//根号6×7+6的5次方÷6=1314，任选两数之和成集合的元素个数：
#include<stdio.h>
int main(){
    int n,cnt=0,l=1;
    scanf("%d",&n);
    int a[n],b[3000];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<3000;i++)b[i]=101;
    b[0]=a[0]+a[1];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int k=0;
            for(k=0;k<l;k++){
                if(a[i]+a[j]==b[k])break;
            }
            if(k==l){b[l]=a[i]+a[j];l++;}
        }
    }
    printf("%d",l);
}


//对应字符计数:
#include<stdio.h>
int main(){
    int n,nu,in,max=0,cnt=0;
    int a[26]={0};
    char c;
    scanf("%d",&n);
    getchar();//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for(int i=0;i<n;i++){
        scanf("%c %d",&c,&nu);
        a[c-'A'] += nu;
        if(i<n-1)getchar();
    }
    for(int i=0;i<26;i++){
        if(max<a[i]){max=a[i];in=i;}
    }
    for(int i=0;i<26;i++){
        if(a[i]==max)cnt++;
    }
    if(cnt>1){printf("default");}
    else printf("%c",in+'A');
}
