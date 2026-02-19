SELECT e.name, e.salary, m.name as manager, m.salary as m_salary FROM Employee as e 
LEFT JOIN Employee as m ON e.managerId = m.id
WHERE e.salary > m.salary;

CREATE TABLE Employee (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    salary INT NOT NULL,
    managerId INT,
    FOREIGN KEY(managerId) REFERENCES Employee(id) ON DELETE SET NULL ON UPDATE CASCADE
);

INSERT INTO Employee (
    name, 
    salary, 
    managerId
) VALUES (
    'Alice (CEO)', 
    150000, 
    NULL
);
INSERT INTO Employee (name, salary, managerId) VALUES ('Bob (Manager)', 90000, 1);
INSERT INTO Employee (name, salary, managerId) VALUES ('Charlie (Dev)', 60000, 2);
INSERT INTO Employee (name, salary, managerId) VALUES ('Charl (DevOps)', 100000, 2);


