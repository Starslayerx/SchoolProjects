# Summerize of CC first project

## 求无限循环小数循环体的位数
### 结果及分析
1. 分子为a 分母为b, 先将a和b化为全为正数的真分数
2. r 为a*10 除以 b 的余数, 其商为a / b 的小数部分
    若r出现0, 则数说明该分数为有限小数
    若r出现重复, 则说明该分数为无限循环小数, 且循环体在此开始重复
3. 通过上述方式, 通过计算出循环体位数即可
可以读取任意整数并给出其循环体位数
### 实验总结及体会
  该实验关键部分是要正确地找到循环体, 通过观测余数r是否重复即可得到该分数是否循环以及循环体, 即可得到循环位数



## 学生成绩信息系统
### 结果及分析
  定义两个类, 一个Students类用来存储单个学生信息, 一个Operations类用来存储操作函数
  可以正常读取文件数据并将数据暂时存储在变量中用于题目要求的操作, 通过将键盘输入传递到单个变量再通过函数可以向文件添加学生信息
### 实验总结及体会
  将学生的信息存储到类中使数据读取和存储更加便捷清晰, 将操作函数放到类中也使
