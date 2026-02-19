SELECT p.firstName, p.lastName, a.city, a.state FROM Address as a 
RIGHT JOIN Person as p ON p.personId = a.personId
ORDER BY p.personId ASC;