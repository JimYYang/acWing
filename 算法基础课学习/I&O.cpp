// 总结c/c++ 中的输入输出问题

1. 单个字符读入问题  整数%d 和字符数组%s都默认以空白为分隔符  而字符%c 默认没有分隔符

https://blog.csdn.net/xia7139/article/details/14522493

char c;
scanf(" %c",&c); // 会跳过空格
scanf("%c", &c); // 不会跳过空格

2. 字符串读入问题 

//cin遇空格即停止
cin >> str; 不读空格

想读入空格
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
[cin cout 优化](https://blog.csdn.net/qq_40430360/article/details/125362584?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-125362584-blog-95493268.pc_relevant_multi_platform_whitelistv1&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-125362584-blog-95493268.pc_relevant_multi_platform_whitelistv1&utm_relevant_index=1)
①
使用
// 关闭输入输出缓存，使效率提升
ios::sync_with_stdio(false);
// 解除cin和cout的默认绑定，来降低IO的负担使效率提升
cin.tie(NULL); cout.tie(NULL);// nullptr 0 NULL 都可以
使用\n 代替endl

5. define 可以定义所有的东西  typedef 可以定义类型

6. 新版的c++ iostream包含了cstdio（scanf printf 需要）
