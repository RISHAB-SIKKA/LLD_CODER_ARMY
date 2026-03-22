# 🚀 LLD Coder Army

> Low-Level Design (LLD) study notes in **C++** covering **OOP**, **SOLID principles**, and **Design Patterns**.  
> Includes **violation vs. fix examples** to build strong design intuition.

---

## 📚 Table of Contents

- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Repository Structure](#repository-structure)
- [Build and Run](#build-and-run)
- [What Each Area Covers](#what-each-area-covers)
- [Learning Goals](#learning-goals)
- [Notes](#notes)

---

## 🧠 Overview

| Topic | What You Practice |
| :--- | :--- |
| **OOP** | Abstraction, Encapsulation, Inheritance, Polymorphism |
| **SOLID** | SRP, OCP, LSP, ISP, DIP |
| **Patterns** | Factory, Builder, Prototype, Singleton, Strategy |

---

## ⚙️ Prerequisites

- A **C++ compiler** (recommended: `g++`)
- **C++11 or newer** (preferably C++17)
- Some files use `<bits/stdc++.h>` (GCC-specific)  
  → Replace with standard headers (`<iostream>`, `<vector>`, etc.) if needed

---

## 📂 Repository Structure

### 🔹 Core Areas

- 📁 [OOP Concepts](./oops_concepts/)
- 📁 [SOLID Principles](./solid_principles/)
- 📁 [Factory Pattern](./factory_pattern/)
- 📁 [Builder Pattern](./builder_pattern/)
- 📁 [Prototype Pattern](./prototype_pattern/)
- 📁 [Singleton Pattern](./singleton_pattern/)
- 📄 [Strategy Pattern](./Lec-7_StrategyPattern.cpp)

---

### 🔹 SOLID Principle Breakdown

- 🔸 [Single Responsibility Principle](./solid_principles/single_responsibility_principle/)
- 🔸 [Open Closed Principle](./solid_principles/open_closed_principle/)
- 🔸 [Liskov Substitution Principle](./solid_principles/liskov_substitution_principle/)
- 🔸 [Interface Segregation Principle](./solid_principles/interface_segeregation_principle/)
- 🔸 [Dependency Inversion Principle](./solid_principles/dependency_inversion_principle/)

---

### ⭐ Highlighted Implementations

- 🔥 [Payment Service Factory Pattern](./factory_pattern/PaymentServiceFactoryPattern.cpp)
- 🔥 [Strategy Pattern Implementation](./Lec-7_StrategyPattern.cpp)
- 🔥 [DIP Correct Implementation](./solid_principles/dependency_inversion_principle/DIP_Correct.cpp)

---

## 🛠️ Build and Run

Each `.cpp` file is standalone and can be compiled individually.

### Compile and run:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic "path/to/File.cpp" -o app && ./app
