# Nachos Project

**Not Another Completely Heuristic Operating System**

This repository contains our coursework for the Operating Systems course.

---

## 📌 Project Details

* **Nachos Version:** 4.0
* **Course:** Operating Systems
* **Implementation Includes:**

  * Custom Absolute Function
  * Priority Scheduler
  * Sleep System Call (with defined time unit)

---

## ⚙️ Installation & Setup

To set up the project, run the following commands:

### 🔹 Step 1: Install Required Tools

```bash
bash install_building_tools.sh
```

### 🔹 Step 2: Build Nachos

```bash
bash build_nachos.sh
```

### 🔹 Step 3: Build COFF to NOFF Translator

```bash
bash coff2noff.sh
```

### 🔹 Step 4: Build and Run Test Cases

```bash
bash build_test.sh
```

---

## 🚀 Quick Setup (All-in-One)

You can also run everything at once using:

```bash
bash full_install.sh
```

---

## 🧪 Testing

All test cases are located in the `code/test` directory.
Make sure all implementations work correctly before submission.

---

## 🔄 CI/CD Integration

This repository includes GitHub Actions for automated workflows.

* Automatically builds the project on every commit
* Runs test cases to ensure correctness
* Helps maintain code quality

✅ **Important:** Ensure all workflows pass successfully before submission.

---

## 📂 Repository Structure

* `code/` → Core Nachos source code
* `code/test/` → Test programs
* Scripts for building and testing

---

## ⚠️ Notes

* Ensure all implementations are complete and tested
* Mention time unit (ticks/seconds) in sleep syscall test cases
* Submit diff files along with this repository link

