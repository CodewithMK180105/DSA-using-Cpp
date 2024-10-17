1. User Input

2. Indexing
    string- C O L L E G E \0
    index-  0 1 2 3 4 5 6 7 

    ASCII values 
        [A-Z]===>{65,90}
        [a-z]===>{97,122}

3. Difference between strings ans character arrays

    a. string is a class and string variables are the objects of this class.
    b. strings include dynamic memory allocation.
    c. no predefined memory allocation.
    d. have inbuilt functions.
    e. slower as compared to array of characters.

    a. array of characters datatype.
    b. static memory allocation.
    c. pre-allocated memory allocation.
    d. doesn't have in built functions.
    e. Faster as compared to strings.

4. Some in built operations 

    a. reverse(str.begin(), str.end())  ==> O(n)
    b. substr(position,length)  ==> O(n)
    c. "+" operator ==>
        str1+=str2;  --->  str2 is appended to str1
        str1=str1+str2;  ---> Copy of string is created for s1 (extra space for string is required).
    d. strcat(str1,str2)
    e. str.push_back(ch);
    f. str.size()/str.length() ==> O(1)
       strlen(ch) ==> O(n)