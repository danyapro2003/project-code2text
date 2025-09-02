# project-code2text

[![Qt](https://img.shields.io/badge/Qt-Widgets-brightgreen)](https://www.qt.io/)
[![C++](https://img.shields.io/badge/C%2B%2B-17-blue)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-lightgrey)](LICENSE)

---

## 📖 Описание (Русский)

**project-code2text** — это утилита на Qt, которая позволяет преобразовывать структуру проекта (файлы, папки, код) в текстовый формат, удобный для работы с искусственным интеллектом.

🔹 Основная идея:

* Выбираете нужные файлы проекта (например, `.h` и `.cpp`),
* Программа собирает их вместе в единый текст, сохраняя структуру,
* Результат можно скопировать и передать ИИ, чтобы он видел проект целиком.

Это удобно, когда нужно задать ИИ вопрос по коду, и важно, чтобы были видны все зависимости и организация проекта.

---

## ✨ Возможности

* Отображение проекта в виде дерева файлов.
* Выбор файлов с помощью галочек.
* Экспорт выбранных файлов в единый текст.
* Сохранение структуры (названия файлов, папок).
* Подготовка кода для анализа ИИ.

---

## 📷 Скриншоты

*Скоро здесь будут примеры интерфейса.*

---

## 🚀 Установка и запуск

```bash
git clone https://github.com/username/project-code2text.git
cd project-code2text
qmake && make
./project-code2text
```

---

## 🛠 Технологии

* C++17
* Qt Widgets

---

## 📌 Планы

* Добавить экспорт сразу в файл `.txt`.
* Настраиваемые шаблоны экспорта.
* Подсветка синтаксиса в окне предпросмотра.

---

## 🌍 English Description

**project-code2text** is a Qt-based utility that converts your project structure (files, folders, code) into a text format suitable for AI processing.

🔹 Main idea:

* Select the project files you need (`.h`, `.cpp`, etc.),
* The program combines them into a single text file while keeping the structure,
* Copy and paste the result into an AI chat to let it "see" your project as a whole.

This is especially useful when you want to ask AI about your code and need the full context.

---

## ✨ Features

* File tree view of the project.
* File selection with checkboxes.
* Export selected files into a single text output.
* Keeps the structure (file and folder names).
* Prepares code for AI analysis.

---

## 📷 Screenshots

*Placeholder for future screenshots.*

---

## 🚀 Build & Run

```bash
git clone https://github.com/username/project-code2text.git
cd project-code2text
qmake && make
./project-code2text
```

---

## 🛠 Tech Stack

* C++17
* Qt Widgets

---

## 📌 Roadmap

* Export directly to `.txt` file.
* Customizable export templates.
* Syntax highlighting in preview window.

---

## 📄 License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
