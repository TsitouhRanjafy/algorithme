SELECT 
    CASE
        WHEN (
            SELECT COUNT(*) FROM Employee
        ) = 1 THEN NULL
        ELSE (
            SELECT salary FROM Employee 
            GROUP BY salary
            ORDER BY salary DESC LIMIT 1,1
        )
    END as SecondHighestSalary;

SELECT 
    CASE
        WHEN (
            SELECT COUNT(*) FROM Emplyee
        ) = 1 THEN NULL
        ELSE (
            SELECT salary FROM Emplyee 
            GROUP BY salary
            ORDER BY salary ASC LIMIT 1,1
        )
    END as SecondMinSalary;


