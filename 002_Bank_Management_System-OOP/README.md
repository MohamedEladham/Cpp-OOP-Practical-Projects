# Bank Management System Using OOP

## Project Overview

This project is a practical application of **Object-Oriented Programming (OOP)** concepts using C++.

The main goal was to build a Bank Management System through a gradual development process, starting with simple client operations and progressively expanding the system to include banking transactions, user management, login functionality, and access permissions.

Instead of developing the entire system at once, the project was divided into smaller, independent stages. Each stage introduced new functionality while reusing components developed in previous stages.

## Development Journey

The project was developed through the following 10 stages:

### 1. Find Client Project

The starting point of the project was implementing the client search functionality.

- Searching for clients using their account numbers.
- Retrieving client information from the data file.
- Introducing the `clsBankClient` class.
- Applying inheritance through `clsPerson`.

### 2. Update Client Project

Adding the ability to modify existing client information.

- Finding an existing client.
- Updating client data.
- Saving the updated information.

### 3. Add Client Project

Implementing the functionality to register new bank clients.

- Reading new client information.
- Validating client data.
- Saving new clients to the data file.

### 4. Delete Client Project

Adding the ability to remove existing clients from the system.

- Searching for the required client.
- Confirming the deletion operation.
- Updating the client records.

### 5. List Clients Project

Implementing a screen to display the registered clients and their information.

### 6. Total Balances Project

Adding functionality to display client balances and calculate the total balances of all registered clients.

### 7. Main Screen Project

Introducing a central main screen to bring together and organize the operations developed in the previous stages.

Instead of accessing each operation separately, users can navigate through the available system features from one central menu.

**Main objectives:**

- Bringing the different operations together in one interface.
- Providing organized navigation between system features.
- Making the system easier to use and extend.
- Allowing additional operations to be introduced in the future.
- Supporting gradual development by allowing some features to remain under development until they are implemented in later stages.

This stage represents an important transition from developing separate operations to organizing them as parts of one integrated application.

### 8. Transactions Project

Introducing banking transaction operations, including:

- Deposit.
- Withdraw.
- Balance-related operations.

### 9. Manage Users Project

Expanding the system to support user management.

- Listing users.
- Adding new users.
- Updating user information.
- Deleting users.
- Finding users.
- Managing user permissions.

### 10. Login & Permissions Project

The final stage of the current development cycle, introducing login functionality and access control.

**Main features:**

- **Login System:** Allowing registered users to access the system using their credentials.
- **Login Register:** Recording login information, including the username, date, and time of each login operation.
- **Permissions System:** Checking the current user's permissions before executing operations. If the user has the required permission, the operation is allowed; otherwise, access is denied.
- **Password Encryption:** Encrypting client and user passwords before storing them in files, including during add and update operations.

With this stage completed, the planned development stages of the current project were reviewed and tested.

## Key OOP Concepts Applied

Throughout the development process, several OOP concepts and programming techniques were applied, including:

- **Classes and Objects:** Organizing the system into classes with specific responsibilities.
- **Encapsulation:** Managing data and operations through class interfaces.
- **Inheritance:** Reusing common functionality through relationships such as `clsBankClient` inheriting from `clsPerson`.
- **Static Members and Methods:** Implementing shared functionality where appropriate.
- **Code Reusability:** Reusing previously developed classes and methods across different stages.
- **File Handling:** Storing and retrieving client and user information using files.

## Gradual Development Approach

One of the main objectives of this project was to understand how a larger application can be developed incrementally.

The development approach focused on:

1. Breaking down a large project into smaller, manageable stages.
2. Implementing and testing each stage independently.
3. Reusing existing classes and components instead of rewriting the same functionality.
4. Extending the system gradually as new requirements were introduced.
5. Organizing separate operations through a central main screen.
6. Maintaining consistency and organization across the different stages.

## Key Lessons Learned

Developing this project from **Find Client** to **Login & Permissions** provided valuable practical experience, including:

- Understanding how to build a larger application step by step.
- Applying OOP concepts in a practical project.
- Improving code organization and class responsibilities.
- Recognizing the importance of code reuse and reducing duplication.
- Understanding how different components interact within one application.
- Learning how to bring independent operations together through a central interface.
- Designing the application to support future extensions and additional features.
- Testing each development stage before moving to the next.

## Project Status

**The 10 planned development stages have been completed.**

The project has evolved from a basic client search operation into a more comprehensive Bank Management System that includes client management, banking transactions, a central main screen, user management, login tracking, and permission control.

This project represents an important step in applying C++ and OOP concepts to a practical application through continuous development and incremental improvement.
