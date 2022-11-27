#include<stdio.h>
#include<unistd.h>
extern int optind,opterr,optopt;
extern char *optarg;
int main(int argc,char *argv[])
{
    int c = 0; //用于接收选项
    /*循环处理参数*/
    while(EOF != (c = getopt(argc,argv,"han:")))
    {
        //打印处理的参数
        printf("start to process %d para\n",optind);
        switch(c)
        {
            case 'h':
                printf("we get option -h\n");
                break;
            case 'a':
                printf("we get option -a\n");
                break;
            //-n选项必须要参数
            case 'n':
                printf("we get option -n,para is %s\n",optarg);
                break;
            //表示选项不支持
            case '?':
                printf("unknow option:%c\n",optopt);
                break;
            default:
                break;
        }    
    }
    return 0;
}