# 🏦 Secure Banking System in C

## 📌 Overview
Simple yet **secure** Banking System in C. Users can create accounts, deposit, withdraw, check balances with **PIN authentication**.

## 🚀 Features
- ✅ Create new bank account (unique acc#, 4-digit PIN)
- ✅ Secure deposit/withdraw with PIN auth
- ✅ Check balance (PIN protected)
- ✅ Display all accounts (admin view)
- ✅ Input validation & bounds checking

## 🔒 Security Improvements
- **Buffer overflow fixed**: fgets for names (<50 chars)
- **PIN authentication**: 4-digit PIN for sensitive ops
- **Input validation**: Positive acc#, amounts; no negatives
- **Unique accounts**: Duplicate acc# rejected
- **Array bounds**: Max 100 accounts enforced

## 🛠️ Technologies
- C + stdio/stdlib/string.h

## 📂 Structure
```
bank-management-system/
├── bank.c          # Main secure app
├── README.md       # This file
└── TODO.md         # Fix progress
```

## ▶️ Run
```bash
gcc bank.c -o bank
./bank
```

**Sample Menu:**
```
===== BANKING SYSTEM =====
1. Create Account
2. Deposit  
3. Withdraw
4. Check Balance
5. Display All Accounts
6. Exit
```

## ⚠️ Limits
- RAM-only (add file I/O next?)
- Max 100 accounts
- Console UI

## 🔮 Future
- File persistence
- User login
- Dynamic accounts
- Encryption

👨‍💻 **Suhas Kumar** | Secure C Dev
