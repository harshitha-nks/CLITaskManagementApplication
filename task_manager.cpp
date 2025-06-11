#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

struct Task {
    int id;
    std::string description;
    std::string deadline;
    int priority;

    std::string to_string() const {
        return std::to_string(id) + "|" + description + "|" + deadline + "|" + std::to_string(priority);
    }

    static Task from_string(const std::string& line) {
        std::stringstream ss(line);
        std::string token;
        Task task;
        std::getline(ss, token, '|');
        task.id = std::stoi(token);
        std::getline(ss, task.description, '|');
        std::getline(ss, task.deadline, '|');
        std::getline(ss, token, '|');
        task.priority = std::stoi(token);
        return task;
    }
};

std::vector<Task> tasks;
const std::string TASK_FILE = "tasks.txt";

void load_tasks() {
    std::ifstream infile(TASK_FILE);
    std::string line;
    while (std::getline(infile, line)) {
        tasks.push_back(Task::from_string(line));
    }
}

void save_tasks() {
    std::ofstream outfile(TASK_FILE);
    for (const auto& task : tasks) {
        outfile << task.to_string() << "\n";
    }
}

void add_task() {
    Task task;
    task.id = tasks.empty() ? 1 : tasks.back().id + 1;

    std::cin.ignore();
    std::cout << "Enter description: ";
    std::getline(std::cin, task.description);
    std::cout << "Enter deadline (YYYY-MM-DD): ";
    std::getline(std::cin, task.deadline);
    std::cout << "Enter priority (1 = High, 2 = Medium, 3 = Low): ";
    std::cin >> task.priority;

    tasks.push_back(task);
    save_tasks();
    std::cout << "Task added.\n";
}

void list_tasks() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.priority < b.priority;
    });

    for (const auto& task : tasks) {
        std::cout << "[" << task.id << "] "
                  << "Description: " << task.description
                  << ", Deadline: " << task.deadline
                  << ", Priority: " << task.priority << "\n";
    }
}

void search_task() {
    std::cin.ignore();
    std::string keyword;
    std::cout << "Enter keyword to search: ";
    std::getline(std::cin, keyword);

    for (const auto& task : tasks) {
        if (task.description.find(keyword) != std::string::npos) {
            std::cout << "[" << task.id << "] " << task.description << " (Deadline: " << task.deadline
                      << ", Priority: " << task.priority << ")\n";
        }
    }
}

void delete_task() {
    int id;
    std::cout << "Enter task ID to delete: ";
    std::cin >> id;

    auto it = std::remove_if(tasks.begin(), tasks.end(), [id](const Task& t) { return t.id == id; });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        save_tasks();
        std::cout << "Task deleted.\n";
    } else {
        std::cout << "Task not found.\n";
    }
}

void menu() {
    int choice;
    do {
        std::cout << "\nTask Manager:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. List Tasks\n";
        std::cout << "3. Search Task\n";
        std::cout << "4. Delete Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: add_task(); break;
            case 2: list_tasks(); break;
            case 3: search_task(); break;
            case 4: delete_task(); break;
            case 5: save_tasks(); break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

int main() {
    load_tasks();
    menu();
    return 0;
}
