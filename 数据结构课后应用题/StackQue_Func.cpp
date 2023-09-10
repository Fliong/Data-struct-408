#include"StackQue.h"

//*************************************
/*栈的初始化*/
void InitStack(SqStack& S) {
	S.top = -1;
}

/*栈的判空*/
bool StackEmpty(SqStack& S) {
	return (S.top == -1) ? true : false;
}

/*入栈*/
bool PushStack(SqStack& S, ElemType x) {
	if (S.top == MAXSIZE - 1) return false;
	S.data[++S.top] = x;
	return true;
}

/*出栈*/
bool PopStack(SqStack& S, ElemType& x) {
	if (!StackEmpty(S)) {
		x = S.data[S.top--];
		return true;
	}
	return false;
}

/*扫描栈内元素*/
void StackPrint(SqStack& S) {
	int len=0 ;
	cout << "该栈内元素为（栈低 --> 栈顶）： ";
	while (len <= S.top) {
		cout << S.data[len++] << " ";
	}
	cout << endl;
}

/*读取栈顶元素*/
ElemType ReadTop(SqStack& S) {
	if (StackEmpty(S)) exit(0);
	return S.data[S.top];
}

/*连续入栈*/
void ContinePush(SqStack& S) {
	ElemType x;
	cout << "请输入栈元素" << endl;
	while (S.top != MAXSIZE - 1) {
		cin >> x;
		if (x != 9999) S.data[++S.top] = x;
		else break;
	}
	StackPrint(S);
}

/*连续出栈*/
void ContinePop(SqStack& S, int len) {
	char op;
	int lenS = S.top;
	ElemType x;       //定义一个变量，打印出栈元素
	if (StackEmpty(S)) {    //判断栈是否为空
		cout << "该栈为空栈" << endl;
		exit(0);
	}
	if ((len - 1) > S.top) {   //栈不为空，则判断请求出栈元素数是否合法
		cout << "请求出栈元素个数大于实际栈内元素，栈中有 "<< lenS + 1 <<"个元素..." << endl;
		cout << "是否继续执行，继续执行则将栈清空，否则重新输入请求数（y/n）:";   //不合法选择下一步操作
		cin >> op;
		switch (op)
		{
		case 'y':    //在不合法的条件下，y: 继续清栈操作，则清空栈
			for (int i = S.top; i >= 0 ; i--) {
				PopStack(S, x);
				cout << x << " ";
			}
			cout << endl;
			break;
		case 'n':     //选择 n: 重新输入出栈的元素个数
			cout << "重新输入出栈的元素个数：";
			cin >> len;
			ContinePop(S, len);
			break;
		default:
			break;
		}
	}
	else {
		for (int i = len; i >0 ; i--) {  //输入合法，连续出栈
			PopStack(S, x);
			cout << x << " ";
		}
		cout << endl;
	}
}

/*共享栈*/
bool ShareStackOp(ShareStack& Shs) {
	Shs.top_1 = 0;
	Shs.top_2 = MAXSIZE - 1;
	int StackNo = 0; // 使用几号栈，0和1
	int top1;
	ElemType x;

	while (Shs.top_2 >= Shs.top_1) {   //栈满判定
		cout << "**输入其他值取消入栈**选择栈（0/1）:";
		cin >> StackNo;
		cout << "[" << StackNo << "]Stack" << "请输入入栈元素:" << endl;
		
		if (StackNo == 0) {
			while (Shs.top_2 >= Shs.top_1) {
				top1 = Shs.top_1;
				cout << "0栈入栈位置" << top1+1 << ":";
				cin >> x;
				if (x != 9999) Shs.data[Shs.top_1++] = x; 
				else break;
			}
		}
		else if (StackNo == 1) {
			while (Shs.top_2 >= Shs.top_1) {
				cout << "1栈入栈位置" << MAXSIZE-Shs.top_2 << ":";
				cin >> x;
				if (x != 9999) Shs.data[Shs.top_2--] = x;
				else break;
			}
		}
		else break;           //若选择0、1以外的栈，则退出
	}

	cout << "栈满！！" << endl;

	cout << "各栈情况：" << endl;
	//0号栈
	cout << "0号栈内容（栈底-->栈顶）:";
	for (int i = 0; i <= Shs.top_1-1; i++) {
		cout << Shs.data[i] << " ";
	}
	cout << endl;

	//1号栈
	cout << "1号栈内容（栈底-->栈顶）:";
	for (int i=MAXSIZE-1; i > Shs.top_2; i--) {
		cout << Shs.data[i] << " ";
	}
	cout << endl;
	return true;
}

/*出入栈操作是否合法判断*/
bool IOStackLegality(char Arryop[]) {
	char push = 'I', pop = 'O';  //设置操作
	int lenA = sizeof(Arryop), i = 0;  //获取数组长度 和遍历单位
	int temp = 0;   //初始化操作为0，每次入栈 +1， 出栈 -1

	while (i<lenA) {     //遍历数组操作符
		if (Arryop[i] == push) {
			temp++;
		}
		else {
			if (temp > 0) temp--;
			else return false;          //排除bug1 : 连续 n 次出栈，再连续 n 次入栈 ，temp=0
		}
		i++;
	}
	
	if (temp == 0)  cout << "操作数合法";
	else cout << "操作数非法";
	return (temp == 0) ? true : false;   //根据temp的值判断操作是否合法
}

/*是否为中心对称字符*/
bool CentralSym(LinkStack& L) {

	LinkStack p = L;
	char s[MAXSIZE];
	int i = 0, j = 0, temp;

	while (p != NULL) {
		if (i > MAXSIZE - 1) break;
		s[i++] = p->data;
		p = p->next;
	}
	i--;

	temp = i % 2;
	while (j != temp+1) {
		if (s[j] == s[i]) { j++; i--; }
		else return false;
	}

	return true;    
}

//***************************
/*队列*/

/*队列初始化*/
void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
	Q.tag = 0;
}

/*扫描队列*/
void PrintQueue(SqQueue& Q) {
	int p1 = Q.front, p2 = Q.rear, temp=Q.tag;
	cout << "该队列元素（队尾-->队头）:";
	while (p1!= p2 || temp==1) {
		if (p2 - 1==0 && temp == 1) p2 = MAXSIZE - 1;
		cout << Q.data[--p2]<<" ";
		temp = 0;
	}
	cout << endl;
}

/*Page 082_01   入队*/
bool InQueue(SqQueue& Q, ElemType x) {
	if (Q.front == Q.rear && Q.tag == 1) return false;  //队列已满
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.tag = 1;
	return true;
}

/*Page 082_01   出队*/
bool OutQueue(SqQueue& Q, ElemType& x) {
	if (Q.front == Q.rear && Q.tag == 0) return false;   //队列为空
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.tag = 0;
	return true;
}


/*Page 082_02   利用栈将队列元素逆置*/
bool QueueTbyStack(SqQueue& Q, SqStack& S) {
	ElemType x;

	while (Q.front != Q.rear || Q.tag == 1) {  //队空标志
		if (OutQueue(Q, x)) 
			if(!PushStack(S, x)) return false;   //如果出队执行成功，则出队元素入栈
	}
	StackPrint(S);           //扫描栈查看元素
	while (S.top != -1) {                  //栈空标志
		if (PopStack(S, x)) 
			if(!InQueue(Q, x)) return false;   //如果出栈成功，则出栈元素入队
	}

	return true;
}