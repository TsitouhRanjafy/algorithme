## 🧩 175. Combine Two Tables  
[View on LeetCode](https://leetcode.com/problems/combine-two-tables/)

### Description
Table: `Person`

| Column Name | Type    |
|--------------|---------|
| personId     | int     |
| lastName     | varchar |
| firstName    | varchar |

`personId` is the primary key column for this table.

Table: `Address`

| Column Name | Type    |
|--------------|---------|
| addressId    | int     |
| personId     | int     |
| city         | varchar |
| state        | varchar |

`addressId` is the primary key column for this table.

Each row of `Person` contains information about the person’s ID, first name, and last name.  
Each row of `Address` contains information about one address, identified by its `addressId`, belonging to one person.

Write an SQL query to report the first name, last name, city, and state of each person in the `Person` table.  
If a person’s address is not in the `Address` table, report `null` instead.

### Example Output
| firstName | lastName | city          | state      |
|------------|-----------|---------------|------------|
| Allen      | Wang      | New York City | New York   |
| Bob        | Alice     | LeetCode      | California |

### Solution (MySQL)
```sql
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p
LEFT JOIN Address a ON p.personId = a.personId;
