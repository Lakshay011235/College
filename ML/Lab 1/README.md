# Lab 1 : Understanding Jupyter Notebooks

## Prescribed Task:

1.1. Launch Jupyter Notebook on your computer.
1.2. Create a new notebook by clicking on the "New" button and selecting "Python 3" from the dropdown menu.
1.3. Familiarize yourself with the interface: cells, toolbar, menu options, etc.
1.4. Rename your notebook to "Intro_to_Jupyter.ipynb".

2.1. Understand the two main types of cells: Code and Markdown.
2.2. Create a new Markdown cell and write a brief introduction to Jupyter Notebooks.
2.3. Create a new Code cell and write a simple Python expression (e.g., 2 + 2).
2.4. Execute the Code cell by pressing Shift + Enter and observe the output.
2.5. Experiment with adding, deleting, and moving cells within the notebook.

3.1. Learn basic Markdown syntax for text formatting (e.g., headings, bold, italic).
3.2. Practice creating Markdown cells with formatted text and headings.
3.3. Insert images and hyperlinks using Markdown syntax.
3.4. Create a Markdown cell with a list of your favorite programming languages.

4.1. Write a Python function that calculates the factorial of a given number.
4.2. Test your function with different input values and observe the results.
4.3. Import a Python library (e.g., NumPy) and use it to perform a mathematical operation (e.g., calculate mean, median).
4.4. Visualize data using Matplotlib or Seaborn libraries within a Jupyter Notebook.

5.1. Understand what a kernel is in the context of Jupyter Notebooks. 
5.2. Learn how to switch kernels in a Jupyter Notebook. 
5.3. If available, switch your notebook's kernel to a different programming language (e.g., R, Julia) and run a simple command. 
5.4. Reset the kernel and clear the outputs. Observe how this affects your notebook.

6.1. Explore different file formats for exporting your Jupyter Notebook: PDF, HTML, slideshows, etc. 
6.2. Export your notebook as a PDF and HTML file.
6.3. Discuss when different export formats might be useful.

7.1. Learn about nbviewer, an online tool to view Jupyter Notebooks. 
7.2. Upload your notebook to a public GitHub repository. 
7.3. Use nbviewer to view your notebook online and share the link with on the document you submit online.

8.1. Learn about interactive widgets in Jupyter and their purpose.
8.2. Create a simple interactive widget (e.g., a slider to input a number).
8.3. Link the widget to a Python function (e.g., modifying a plot based on the widget's input).

9.1. Learn about Jupyter Notebook extensions (e.g., Jupyter_contrib_nbextensions). 
9.2. Install any chosen extension and demonstrate its functionality in your notebook.

## Additional Tasks: (Lab 1.A : Introduction to Google Colab)

1.1. Access Google Colab by visiting colab.research.google.com.
1.2. Create a new notebook in Google Colab.
1.3. Familiarize yourself with the Colab interface including the menu, toolbar, and cells.

2.1. Write and execute a simple Python command (e.g., print statement).
2.2. Create and manipulate Python lists and dictionaries.
2.3. Define and call a simple Python function.

3.1. Learn how to mount Google Drive in Colab using drive.mount('/content/drive').
3.2. Access a file from your Google Drive by navigating through the directory structure in Colab.
3.3. Read a sample data file (e.g., CSV or Excel) from Drive into a pandas DataFrame.

4.1. Perform basic data analysis operations (like sorting, filtering) on the DataFrame.
4.2. Use Matplotlib or Seaborn to create a simple visualization (e.g., line chart, histogram) of the data.

5.1. Explore some of the pre-installed Python libraries in Colab.
5.2. Install a new Python library (not already available in Colab) and demonstrate its basic functionality.

6.1. Learn how to share your Colab notebook with others.
6.2. Explore the 'Comments' and 'Version History' features to understand how collaboration is facilitated in Colab.

7.1. Save your notebook to Google Drive.
7.2. Export your notebook in different formats (e.g., .ipynb, .pdf) and save them to your Drive.

---

### Record 1

1.1 > Typed `jupyter notebook` in terminal and pressed Enter.
1.2 > Clicked "New" from top-right and selected "Python 3".
1.3 > Cell Types [md , code] / Toolbar / Menu
1.4 > Clicked the name of the notebook to rename.

2.1 > Refer 1.3
2.2 > Created .md content.
2.3 > Write vanilla python expression (2 + 2)
2.4 > Generated output by pressing shortcut to run (Ctrl+Enter).
2.5 > Other shortcuts (Ctrl+Enter) , (Esc+A) and (Ctrl+B).

3.1 > Markdown syntax... Headings, Bold, Italics, Lists, Links, Images, Rulers.
3.2 > Wrote sample markdown content.
3.3 > Inserted Images
3.4 > Wrote md for languages I like.

4.1 > Func{ Factorial : Recursive + no-memo}
4.2 > Eval Func
4.3 > import numpy + sample functions
4.4 > import matplotlib + sample plot

5.1 > Kernel is computational engine (main thread) that runs all the code contained in notebook.
5.2/3 > Switch Kernels - no other kernel available (^人^)
5.4 > Restarted kernel

6.1 > MD >> PDF, HTML
6.2 > File > "Download as"
6.3 > PDF (static , non-interactive) and HTML (interactive)

7.1 > nbviewer : renders notebooks as static pages
7.2 > Already done.
7.3 > github_link > nbviewer.

8.1 > Widgets : Interactive control for data manipulations in notebook.
8.2 > Coding...
8.3 > Linking...

9.1 > Extensions : Add functionality to notebook.
9.2 > NO, I don't want to unless I need to. (＞︿＜)

### Record 1.A

1.1 > Accessed Colab through gmail.
1.2 > New notebook made.
1.3 > Menu / Toolbar / Cells

2.1 > python >>> Hello Colab
2.2 > Python lists and dicts.
2.3 > Python >>> greet(_name)

3.1 > Mounting drive : Lets colab use my drives content (Security Issue).
3.2 > use os lib to explore drive.
3.3 > pandas > open_csv

4.1 > sort and filter (basic data analysis)
4.2 > yay! Plotting time!

5.1 > using !pip command in colab kernel. `!pip list` to see all pre-installed (a lot)
5.2 > install scikit-learn.

6.1 > Sharable link.
6.2 > Comments and revision history.

7.1 > Auto-save / Save copy in drive
7.2 > Export as 'ipynb' or 'pdf' or 'html' > drive / local.