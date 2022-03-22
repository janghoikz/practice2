#include <iostream>

enum Command
{
    PUSH = 1,
    POP = 2,
    EXIT = 3
};

const int Queue_SIZE{ 9 };

struct Queue
{
    int array[Queue_SIZE]{};
    int head = 0;
    int tail = 0;
};

void PrintInfo()
{
    std::cout << "<Queue>" << std::endl;
    std::cout << "[1] push" << std::endl;
    std::cout << "[2] pop" << std::endl;
    std::cout << "[3] exit" << std::endl;
    std::cout << "-------------" << std::endl;
}

void PrintStack(Queue& Queue)
{
    
    for (int i = 0; i < Queue_SIZE; i++)
    {
        std::cout << Queue.array[i] << std::endl;
    }
    std::cout << "-----------------";
}

void Push(Queue& Queue, int value)
{
    Queue.array[Queue.tail++] = value;
}

void Pop(Queue& Queue)
{
    std::cout << Queue.array[Queue.head] << "를 꺼냈습니다." << std::endl;
    std::cout <<  "-----------" << std::endl;
    for (int i = 0; i < 9; i++)
    {
        int temp = 0;
        Queue.array[i] = Queue.array[i + 1];
        if (i == 8)
        {
            Queue.array[i + 1] = 0;
        }
    }
    Queue.tail--;
}

void ProcessUserInput(Queue& Queue)
{
    int command{};
    bool isExit{ false };

    while (command != EXIT)
    {
        PrintStack(Queue);
        std::cout << std::endl << "> ";
        std::cin >> command;
        switch (command)
        {
        case PUSH:
        {
            int value;
            std::cout << "    Value>>";
            std::cin >> value;
            Push(Queue, value);
            break;
        }

        case POP:
            Pop(Queue);
            break;

        case EXIT:
            isExit = true;
            break;

        default:
            std::cout << "잘못된 명령어 입니다." << std::endl;
            break;
        }

        if (isExit)
        {
            break;
        }
    }
}

int main()
{
    Queue myQueue;

    PrintInfo();
    ProcessUserInput(myQueue);
}