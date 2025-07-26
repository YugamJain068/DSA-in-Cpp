#include<iostream>
#include<string>
using namespace std;

class todolist{
    private:
    string tasks[100];
    int task_count;
    public:
    todolist():task_count(0){}
    void addtask(const string& task){
        if (task_count >= 100){
            cout<<"Error ! Task list is full!"<<endl;
            return ;
        }
        tasks[task_count++]=task;
        cout<<"Task added successfully !"<<endl;
        cout<<"\n";
    }
    void viewtasks(){
        if (task_count==0){
            cout<<"No task in the list!"<<endl;
            return;
        }
        cout<<"\n Your To-Do List:"<<endl;
        for (int i=0;i<task_count;++i){
            cout<<i+1<<"."<<tasks[i]<<endl;
        }
    }
    void deletetask(int taskNo){
        if(taskNo<1 || taskNo>task_count){
          cout<<"invalid task number!"<<endl;
          return ;  
        }
        for (int i=taskNo-1; i<task_count-1;++i){
            tasks[i]=tasks[i+1];
        }
        --task_count;
        cout<<"Task deleted "<<endl;
    }

};
int main(){
    todolist list;
    int choice;
    string task;
    int tasknumber;
    do{
        cout<<" ____TO DO LIST___"<<endl;
        cout<<"1.Add task"<<endl;
        cout<<"2.View Tasks"<<endl;
        cout<<"3.Delete Task"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1:
            cout<<"Enter the task:";
            getline(cin,task);
            list.addtask(task);
            break;

            case 2:
            list.viewtasks();
            break;

            case 3:
            cout<<"Enter the task number to delete :";
            cin>>tasknumber;
            list.deletetask(tasknumber);
            break;

            case 4:
            cout<<"Existing from to do list. Have a nice day !"<<endl;
            break;

            default:
            cout<<"Wrong choice !"<<endl;
        }
    }while(choice!=4);
    return 0;
}