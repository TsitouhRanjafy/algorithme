[here](https://leetcode.com/problems/duplicate-emails/description/)


## Solution


It's easy to find duplicates with one field:

```sql
SELECT email, COUNT(email) 
FROM users
GROUP BY email
HAVING COUNT(email) > 1
```

So if we have a table

```
ID   NAME   EMAIL
1    John   asd@asd.com
2    Sam    asd@asd.com
3    Tom    asd@asd.com
4    Bob    bob@asd.com
5    Tom    asd@asd.com
```

This query will give us **John**, **Sam**, **Tom**, **Tom** because they all have the same email.

However, what I want is to get duplicates with the same `email` and `name`.

That is, I want to get **Tom**, **Tom**.


solution

```sql
SELECT name, email, COUNT(*)
FROM users
GROUP BY name, email
HAVING COUNT(*) > 1
```
