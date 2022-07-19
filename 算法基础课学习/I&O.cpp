// 总结c/c++ 中的输入输出问题

1. 单个字符读入问题
char c;
scanf("%c ",&c); // 会跳过空格
scanf("%c", &c); // 不会跳过空格

2. 字符串读入问题 

//cin遇空格即停止
cin >> str; 不读空格
//对于string类型，可使用
string str;
getline(cin,str);

//对于字符型数组，可使用

①char str[50];
scanf("%[^\n]",chs);
②cin.get(chs,max_num);
③cin.getline(str,max_num);


3. 输入控制循环问题
int x;
while(cin >> x); // 速度慢
while(~scanf("%d", &x) or while(scanf("%d", &x) != EOF) // 速度快

      
4. 优化cin问题
