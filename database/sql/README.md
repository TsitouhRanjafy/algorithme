## 🗄️ How to Execute SQL Files in MySQL

Follow these steps to run a .sql script via the Command Line Interface (CLI).


### Method 1: Interactive Mode (Inside MySQL)  

Best if you are already logged in or need to run multiple scripts in a row.

1.**Connect to the MySQL server**:

```bash
mysql -h <host> -u <username> -p
```

2.**Select your database**:

```sql
USE <db-name>
```
### Method 2: The "One-Liner" (Direct from Terminal)

Best for quick executions or automation scripts. You don't need to enter the MySQL prompt first.

```bash
mysql -h <host> -u <username> -p <database_name> < /path/to/your/file.sql
```

