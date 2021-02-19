#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

TaskStatus Next(const TaskStatus& t){
    return static_cast<TaskStatus>(static_cast<int>(t)+1);
}
void RemoveZeros(TasksInfo& t){
    vector<TaskStatus> v;
    for(auto& [status, col]: t)
        if(col == 0)
            v.push_back(status);

    for(auto& i: v)
        t.erase(i);
}


class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const;

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person);

  // Обновить статусы по данному количеству задач конкретного разработчика,
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count);
private:
    map<string, TasksInfo> person_tasks;
};

const TasksInfo &TeamTasks::GetPersonTasksInfo(const string &person) const {return person_tasks.at(person);}
void TeamTasks::AddNewTask(const string &person) {++person_tasks[person][TaskStatus::NEW];}

tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const string &person, int task_count) {
    TasksInfo updated_tasks, untouched_tasks;
    TasksInfo& tasks = person_tasks[person];

    //Формируем запрос на измененния
    for(auto& [status, col]: tasks)
        if(status != TaskStatus::DONE)
            task_count -= updated_tasks[Next(status)] = min(task_count, col);



    //Изменяем
    for(auto status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)){
        untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
        tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
    }


    tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];
    RemoveZeros(updated_tasks);
    RemoveZeros(untouched_tasks);
    RemoveZeros(person_tasks.at(person));

    return {updated_tasks, untouched_tasks};
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}









