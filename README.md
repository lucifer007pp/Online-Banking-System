# 💰 Online Banking System (C Language)

A simple **command-line banking system** written in **C**, simulating basic banking operations such as account registration, login, balance management, deposits, and withdrawals. User data is stored and retrieved using files based on phone numbers.

## 🧠 Features

- ✅ Register a new account
- 🔐 Login to an existing account
- 💸 Withdraw and deposit money
- 💾 User data persistence using `.dat` files
- 📱 Each account is tied to a unique phone number and account number

## 🛠️ Technologies Used

- C Programming Language
- File handling using `fopen`, `fwrite`, `fread`
- Structs for user data representation
- CLI interface for user interaction

## 🧾 How It Works

### Registration
- User provides:
  - Account number
  - Phone number
  - Password
- Data is stored in a file named `<phone>.dat`

### Login
- User logs in using:
  - Account number
  - Password
- Data is read from the file `<password>dat` *(note: this is a bug — it should be `<phone>.dat`)*

### Post-login Options
- 💰 **Withdraw:** Deducts amount from balance
- 💵 **Deposit:** Adds amount to balance
- 📉 Displays previous and updated balance after each transaction


