# CLI Task Manager in C++

##  Project Summary

This is a simple **command-line task manager** built in **C++** for Linux-based systems. The application allows users to:

- Create tasks with a **description**, **deadline**, and **priority level**
- View all tasks (sorted by priority)
- Search for tasks using keywords
- Delete tasks by ID
- Persist task data in a local file (`tasks.txt`)

It is designed for lightweight productivity tracking directly from the terminal, with a minimal footprint and no external dependencies beyond the C++ Standard Library.

---

## How to Build and Run (Linux)

1. **Clone or Download** the project to your local machine:

   ```
   git clone <repo-url>
   ```
2. **Compile the program**:
   ```
   g++ task_manager.cpp -o task_manager
   ```
3. **Run the application**:
   ```
   ./task_manager
   ```
4. (Optional) Create an empty task file (if not already present):
   ```
   touch tasks.txt
   ```
---
## Feature List
| Feature         | Description                                             |
| --------------- | ------------------------------------------------------- |
| Add Task        | Input task description, deadline, and priority (1-3)    |
| List Tasks      | View all tasks sorted by priority                       |
| Search Task     | Search tasks using keywords in description              |
| Delete Task     | Delete a task by its numeric ID                         |
| Persistent Save | Tasks are automatically saved to `tasks.txt` on changes |
---
## Files Included
| File               | Purpose                                |
| ------------------ | -------------------------------------- |
| `task_manager.cpp` | Main application code                  |
| `tasks.txt`        | Local file to store tasks persistently |
| `README.md`        | Documentation for setup and usage      |
---
## Notes
- Priorities are sorted as: 1 (High), 2 (Medium), 3 (Low)
- Deadlines are not validated for format; ensure correct YYYY-MM-DD
- No external dependencies required (just g++ and stdlib)


