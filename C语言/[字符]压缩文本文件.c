/*一种压缩文本文件（假设文件中不包含数字）的方法如下：
    1. 原始文本文件中的非字母的字符，直接拷贝到压缩文件中；
    2. 原始文件中的词（全部由字母组成），如果是第一次出现，则将该词加入到一个词的列表中，并拷贝到压缩文件中；
		否则该词不拷贝到压缩文件中，而是将该词在词的列表中的位置拷贝到压缩文件中。
    3. 词的列表的起始位置为 1 。 词的定义为文本中由大小写字母组成的最大序列。大写字母和小写字母认为是不同的字母*/
	
#include<stdio.h>
#include<string.h>
#define MAX_DIC_SIZE 3000
#define MAX_WORD_SIZE 80
#define MAX_LEN 100
int is_letter(char x){
	return ((x<='z'&&x>='a')||(x<='Z'&&x>='A'));
}
int main(){
	char input[MAX_LEN];
	char dic[MAX_DIC_SIZE][MAX_WORD_SIZE+1]={0};
	int start=1;
	//读取输入，将每一行存到input里面
	while(fgets(input,sizeof(input),stdin)!=NULL){
		//遍历这一行输入
		int i=0;
		while(input[i]!='\0'){
			//1：是字母->存储到临时的数组temp
			if(is_letter(input[i]))
			{
				//初始化，防止旧的数据残留
				char temp[MAX_WORD_SIZE]={0};	
				int len=0;
				//存储当前单词（是字母&&连续）						
				do {
        			temp[len++]=input[i++];
    			} while (is_letter(input[i]) && len < MAX_WORD_SIZE);
				//在字典中查找：找到&未找到
				int found=0,index;
				for(index=1;index<MAX_DIC_SIZE;index++){
					if(strcmp(temp,dic[index])==0){
						found=1;
						break;
					}
				}
				//1：找到：直接打印index
				if(found){
					printf("%d",index);
				}
				//2.未找到：打印单词并存入字典
				else{
					printf("%s",temp);
					strcpy(dic[start],temp);
					start++;
				}
			}
			//2:非字母->直接输出
			else{
				printf("%c",input[i]);
				i++;
			}
		}

	}
	return 0;
}