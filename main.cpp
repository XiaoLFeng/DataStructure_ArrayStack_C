/*
 * ����˵��
 * ������ ���xiao_lfeng ��д
 * �俪�����ɴ˻�����ICP�������߱�д����ICP��2022014822��
 */

#include <cstdio>
#include <cstdlib>

#define MaxSize 100

typedef int datatype;
typedef struct {
    datatype data[MaxSize];
    int top;
} SqStack;

//������ʼ��һ��˳��ջ:
void InitStack(SqStack &stack) {
    stack.top = 0;
}

// ����ʵ��Ԫ�ص���ջ����:
int Push(SqStack &stack, int data) {
    if (stack.top + 1 > MaxSize) return 0;
    stack.data[stack.top] = data;
    stack.top++;
    return 1;
}

//����ʵ��Ԫ�صĳ�ջ����:
int Pop(SqStack &stack) {
    if (stack.top != 0) {
        stack.top--;
        return stack.data[stack.top];
    } else {
        return -99999;
    }
}

//����ʵ��ȡջ��Ԫ�صĲ�����
int GetTop(SqStack stack) {
    return stack.data[stack.top-1];
}

void GetAll(SqStack stack) {
    if (stack.top != 0) {
        printf("[SELECT] ���ȫ�����ݣ�[ ");
        int size = stack.top-1;
        while (size) {
            printf("%d, ",stack.data[size]);
            size = size - 1;
        }
        printf("%d ]\n",stack.data[0]);
        printf("\n");
    } else {
        printf("[WARNING] ջ��ΪΪ��\n");
        printf("\n");
    }
}

int main() {
    SqStack stack;
    InitStack(stack);
    int ch,data;
    Start:
    printf("[INFO] ˳��ջ����\n");
    printf("\t======================\n");
    printf("\t��ѡ��\n");
    printf("\t1����ջ\n");
    printf("\t2����ջ\n");
    printf("\t3��ȡջ��Ԫ��\n");
    printf("\t4���鿴ȫ��Ԫ��\n");
    printf("\t0���˳�\n");
    printf("\t======================\n");
    printf("\tѡ��(0, 1, 2, 3, 4): ");
    scanf_s("%d",&ch);
    printf("\n");

    switch (ch) {
        case 1:
            printf("[INSERT] ������Ҫ����Ԫ�أ�");
            scanf_s("%d",&data);
            if (Push(stack,data)) {
                printf("[SUCCESS] ��ջ���\n");
                printf("\n");
            } else {
                printf("[FAIL] ��ջʧ��\n");
                printf("\n");
            }
            goto Start;
        case 2:
            printf("[OUTPUT] ��ջ���ݣ�%d\n", Pop(stack));
            printf("\n");
            goto Start;
        case 3:
            printf("[SELECT] ջ�����ݣ�%d\n",GetTop(stack));
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