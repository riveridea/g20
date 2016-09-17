/*

题目：数组中有一个数字的出现次数超过了数组长度的一半，找出这个数字。

*/

所以我们如果用一个key值记录数组中的数字，
然后用一个value记录该数字出现的次数，然后累加：
继续遍历余下的所有数字，如果和这个数字相等，就把次数加1；
如果和这个数字不等，那么就把该数字的次数减1；如果某数字的出现次数为0，
那么我们就用下一个数字替换之，然后重置出现次数为1。
这样最后剩下的数字肯定就是出现次数超过数组长度一半的数字。

#include<iostream>
#include<string>
using namespace std;

//全局变量，检查输入是否有效
bool invalidInput = false;

/************************************************************
/* 找出数组中出现次数超过数组长度一半的数字
/************************************************************/
int NumberAppearMoreThanHalf(int* numbers,unsigned int length)
{
    if(numbers == NULL || length <= 0)
    {
        invalidInput = true;
        return 0;
    }

    invalidInput = false;
    int key = numbers[0];
    unsigned int appearTimes = 1;
    for(int i = 1;i < length;++i)
    {
        if(appearTimes == 0)
        {
            key = numbers[i];
            appearTimes = 1;
        }

        if(numbers[i] == key)
            appearTimes++;
        else
            appearTimes--;
    }
    
    //检验输入的数组是含有满足条件的数字
    appearTimes = 0;
    for(i = 0; i < length; i++)
    {
        if(numbers[i] == key)
            appearTimes++;
    }

    if(appearTimes <= length / 2)
    {
        invalidInput = true;
        return 0;
    }
    
    return key;
}

int main()
{
    cout<<"Enter the length of your array:"<<endl;
    int arraylength = 0;
    cin>>arraylength;

    cout<<"Enter the elements of your array:"<<endl;
    int *array = new int[arraylength];
    for(int k = 0; k < arraylength;k++)
    {
        cin>>array[k];
    }

    cout<<"the number appear more than half length of your array is:"<<endl;
    cout<<NumberAppearMoreThanHalf(array,arraylength)<<endl;
    
    delete[] array;
    
    return 0;
}