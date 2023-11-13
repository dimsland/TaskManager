<!DOCTYPE html>

<body>
    <h1>TaskManager - Menu Functionality</h1>
    <ul>
        <li>
            <h2>void menu(Language lang, MenuColors colors, Task tasks[], int taskCount)</h2>
            <p>This function displays the main menu, utilizing Language and MenuColors structures for multilingualism and color schemes. Displays warnings for undefined menu items or colors.</p>
        </li>
        <li>
            <h2>void printTasks(Language lang, Task tasks[], int taskCount)</h2>
            <p>Outputs all tasks in a readable format, including details like description, deadline, priority, and status.</p>
        </li>
        <li>
            <h2>void printTaskStatus(Language lang, Task tasks[], int taskCount)</h2>
            <p>Provides an overview of task statuses, counting tasks in each status category (e.g., completed, incomplete).</p>
        </li>
        <li>
            <h2>void scanTasks(Language lang, Task tasks[], int taskCount)</h2>
            <p>Enables data entry for new tasks (description, priority, status, deadline) and adds them to the task list.</p>
        </li>
        <li>
            <h2>int deleteTasks(Language lang, Task tasks[], int taskCount)</h2>
            <p>Allows task deletion from the list by selecting a task's index. Returns updated task count after deletion.</p>
        </li>
        <li>
            <h2>void changeTasks(Language lang, Task tasks[], int taskCount)</h2>
            <p>Enables changing of a task's status to its opposite. A notification is displayed upon status change.</p>
        </li>
        <li>
            <h2>void changeTask(Language lang, Task tasks[], int taskCount)</h2>
            <p>Sets the status of all tasks to "Completed", allowing quick status updates for all tasks.</p>
        </li>
    </ul>
</body>
</html>
