/*
 * 代码说明
 * 代码由 筱锋xiao_lfeng 编写
 * 其开发者由此互联网ICP备案作者编写：粤ICP备2022014822号
 */

#include <cstdio>
#include <cstdlib>

#define MaxSize 100

typedef int datatype;
typedef struct {
    datatype data[MaxSize];
    int top;
} SqStack;

//用来初始化一个顺序栈:
void InitStack(SqStack &stack) {
    stack.top = 0;
}

// 用来实现元素的入栈操作:
int Push(SqStack &stack, int data) {
    if (stack.top + 1 > MaxSize) return 0;
    stack.data[stack.top] = data;
    stack.top++;
    return 1;
}

//用来实现元素的出栈操作:
int Pop(SqStack &stack) {
    if (stack.top != 0) {
        stack.top--;
        return stack.data[stack.top];
    } else {
        return -99999;
    }
}

//用来实现取栈项元素的操作。
int GetTop(SqStack stack) {
    return stack.data[stack.top-1];
}

void GetAll(SqStack stack) {
    if (stack.top != 0) {
        printf("[SELECT] 输出全部数据：[ ");
        int size = stack.top-1;
        while (size) {
            printf("%d, ",stack.data[size]);
            size = size - 1;
        }
        printf("%d ]\n",stack.data[0]);
        printf("\n");
    } else {
        printf("[WARNING] 栈表为为空\n");
        printf("\n");
    }
}

int main() {
    SqStack stack;
    InitStack(stack);
    int ch,data;
    Start:
    printf("[INFO] 顺序栈操作\n");
    printf("\t======================\n");
    printf("\t请选择\n");
    printf("\t1：入栈\n");
    printf("\t2：出栈\n");
    printf("\t3：取栈项元素\n");
    printf("\t4：查看全部元素\n");
    printf("\t0：退出\n");
    printf("\t======================\n");
    printf("\t选择(0, 1, 2, 3, 4): ");
    scanf_s("%d",&ch);
    printf("\n");

    switch (ch) {
        case 1:
            printf("[INSERT] 请输入要插入元素：");
            scanf_s("%d",&data);
            if (Push(stack,data)) {
                printf("[SUCCESS] 入栈完成\n");
                printf("\n");
            } else {
                printf("[FAIL] 入栈失败\n");
                printf("\n");
            }
            goto Start;
        case 2:
            printf("[OUTPUT] 出栈数据：%d\n", Pop(stack));
            printf("\n");
            goto Start;
        case 3:
            printf("[SELECT] 栈顶数据：%d\n",GetTop(stack));
            printf("\n");
            goto Start;
        case 4:
            GetAll(stack);
            goto Start;
        default:
            break;
    }
    system("pause");
    return 0;
}