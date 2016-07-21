#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stack>
using namespace std;
typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char** HuffmanCode;
typedef struct
{
	char lette;
	int weight;
}letter;
void Select(HuffmanTree &HT, int n, int &s1, int &s2)
{
	int j;
	for (j = 1; j <= n && HT[j].parent != 0; j++);
	s1 = j;
	for (j = 1; j <= n; j++)
		if (HT[j].parent == 0 && HT[j].weight < HT[s1].weight)  s1 = j;
	HT[s1].parent = 1;
	//same
	for (j = 1; j <= n&&HT[j].parent != 0; j++);
	s2 = j;
	for (j = 1; j <= n; j++)
		if (HT[j].parent == 0&&HT[j].weight<HT[s2].weight) s2 = j;
}
void InitHuffmanTree(HuffmanTree &HT,letter* &w,int &n)
{
	int m,i;
	FILE* fp;
	HuffmanTree p;
	printf("请输入字符个数");
	scanf("%d", &n); getchar();
	m = 2 * n - 1;
	fp = fopen("hfmtree.txt", "w");
	if (n <= 1) return;
	w = (letter *)malloc(m*sizeof(letter));
	for (int i = 0; i <= m; i++) { w[i].lette = 0; w[i].weight = 0; }
	printf("分别输入字符和权值:\n");
	for (int i = 1; i <= n; i++)
	{
		scanf("%c %d", &w[i].lette, &w[i].weight);
		getchar();
	}
	HT = (HuffmanTree)malloc((m + 1)*sizeof(HTNode));
	memset(HT, 0, (m+1)*sizeof(HTNode));
	for (p = HT, i = 0; i <= n; ++i, ++p) (*p).weight = w[i].weight;
	for (i = n + 1; i <= m; i++)
	{
		int s1, s2;
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	fprintf(fp, "%s", "标号 字符 权值 父亲 左儿子 右儿子\n");
	for (i = 1; i <= m; i++)
		fprintf(fp, "%d     %c     %d    %d     %d      %d\n", i, w[i].lette, w[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	fclose(fp);
	printf("\n初始化成功\n");
}
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n,letter* w)
{
	int i; char* cd; char* p; char c;
	FILE* fp1, *fp2;
	fp1 = fopen("tobetrans.txt", "w");
	fp2 = fopen("codefile.txt", "w");
	printf("请输入要翻译的内容：\n");
	while(scanf("%c", &c)&&c!='\n') fputc(c, fp1);
	fclose(fp1);
	fp1 = fopen("tobetrans.txt", "r");
	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
	cd=(char*)malloc(n*sizeof(char));
	p = (char*)malloc(sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++)
	{
		int start=n-1;
		for(int c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
			if(HT[f].lchild==c) cd[--start]='0';
			else cd[--start]='1';
		HC[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
	while (fread(p, 1, 1, fp1) != 0)
	{
		for (i = 1; i <= n; i++)
			if (*p == w[i].lette) fprintf(fp2, "%s", HC[i]);
	}
	fclose(fp1);
	fclose(fp2);
	printf("\n编码成功\n");
}
void HuffmanTrans(HuffmanTree HT, letter*  w, int n)
{
	FILE* fp1, *fp2;
	fp2 = fopen("textfile.txt", "w");
	fp1 = fopen("codefile.txt", "r");
	int m = 2 * n - 1,t,i=0,flag=1;
	char* text = NULL; char* p; 
	p = (char*)malloc(sizeof(char));
	while (fread(p, 1, 1, fp1))
	{
		t = m;
		while (w[t].lette == NULL)
		{
			if (*p == '0') t = HT[t].lchild;
			else t = HT[t].rchild;
			if (fread(p, 1, 1, fp1) == 0) { flag = 0; }
		}
		if(flag) fseek(fp1, -1, SEEK_CUR);
		if (i == 0) { text = (char*)malloc(sizeof(char)); text[i] = w[t].lette; }
		else { text = (char*)realloc(text, (i + 2)*sizeof(char)); text[i] = w[t].lette; }
		i++;		
	}
	text[i] = '\0';
	fprintf(fp2, "%s", text);
	fclose(fp1);
	fclose(fp2);
	printf("\n译码成功\n");
}
void visit(int x, int i,FILE *fp)
{
	for (int j = 0; j < 3 * i; j++)
		fputc(' ',fp);
	fprintf(fp,"%d\n",x);
	for (int j = 0; j < 3*i; j++)
		printf(" ");
	printf("%d\n", x);
}
void PrintHuffmanTree(HuffmanTree HT,int m)
{
	stack<HTNode> s; int p = m, i = 0,j=0,flag=0,num=1; HTNode t;
	FILE* fp;
	fp = fopen("treeprint.txt", "w");
	while (p||!s.empty())	{
		if (p) {
			s.push(HT[p]);
			i++;
			p = HT[p].rchild;
		}
		else {
			if (flag) { j = 0; flag = 0; }
			t = s.top(); 
			s.pop(); 
			visit(t.weight, i,fp);
			p = t.lchild;
			if (!p) {  i -= 1 + j; j = 0; }
			else { j = 1; if (i == num) { flag = 1; num++; }}
		}
	}
	fclose(fp);
}
void PrintHuffmanCode()
{
	FILE* fp; char* p = (char*)malloc(1);
	fp = fopen("codefile.txt", "r");
	printf("\n");
	while (fread(p, 1, 1, fp) != 0) printf("%c", *p);
	printf("\n");
}
char enterChoice()
{
	char menuChoice; 

					
	printf("\n请输入您的选择\n");
	printf("I - 初始化哈夫曼树\n");
	printf("C - 编码\n");
	printf("D - 译码\n");
	printf("P - 打印代码文件\n");
	printf("T - 打印哈夫曼树\n");
	printf("E - 退出程序\n");
	printf("您的选择:");
	scanf("%c", &menuChoice); 
	getchar();
	return menuChoice;

}
int main()
{
	HuffmanTree ht=NULL; letter* w = NULL;
	int n=0,i=0; HuffmanCode hc; char choice;
	while ((choice = enterChoice()) != 'E')
	{
		switch (choice)
		{
		case 'I':
			InitHuffmanTree(ht, w, n);
			break;
		case 'C':
			HuffmanCoding(ht, hc, n, w);
			break;
		case 'D':
			HuffmanTrans(ht, w, n);
			break;
		case 'P':
			PrintHuffmanCode();
			break;
		case 'T':
			PrintHuffmanTree(ht,2*n-1);
			break;
		default:
			printf("Incorrect choice\n");
			break;
		}
	}
	return 0;
}