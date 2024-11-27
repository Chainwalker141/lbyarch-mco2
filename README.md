# lbyarch-mco2
MCO2 project for lbyarch (Sinjian, So)

# SPECS
![cbab51df-1a4c-40a7-8211-20e7ce056902](https://github.com/user-attachments/assets/88898778-90e3-4293-978c-de77933955c6)
![67bf63cc-de6b-41bd-b36a-ec9b7bcf6c12](https://github.com/user-attachments/assets/b31389bd-e10a-4651-acf4-801acfbdf483)
![086cfd95-70fa-4c79-bf53-6bd281942928](https://github.com/user-attachments/assets/60b7862f-89ae-4818-88d4-4700c6ddbe64)

# I. COMPARISON AND ANALYSIS

Excel Sheet: https://docs.google.com/spreadsheets/d/1JPBbA4TByGVgUIVufFvhg9etAgxCbArouISoaOKwPk8/edit?gid=0#gid=0

![image](https://github.com/user-attachments/assets/445cf748-4c77-4cca-9418-0cb1c59f9ca7)

Each version has been run 30 times to determine the average execution time.

- For 2^20, The average time is 0.0078s.
- For 2^24, The average time is 0.1032333333s.
- For 2^29, The average time is 4.596566667s.

An observation shows that it takes more time to run a kernel with a larger vector size while it takes less time for it to run with a smaller vector size. When running the kernel with a vector size of 2^30, the program would indefinitely run, seeing as the machine could not handle it, we reduced the last version to 2^29 to where it can be supported.

# II. C PROGRAM CORRECTNESS CHECKS (AND OFFICIAL TESTCASES)
  1. Example provided in project specs
    X1 -> 1.5, 4.0, 3.5, 2.0
    X2 -> 3.0, 2.5, 2.5, 1.0
    Y1 -> 4.0, 3.0, 3.5, 3.0
    Y2 -> 2.0, 2.5, 1.0, 1.5
    Z -> 2.5, 1.58113883, 2.692582404, 1.802775638
    ![image](https://github.com/user-attachments/assets/5ae94756-59c4-4c2f-9ac3-6eb34bd7ad5b)
  2. Each value having the same large value (no distance hence 0)
  	X1 -> 2000000
    X2 -> 2000000
    Y1 -> 2000000
    Y2 -> 2000000
    Z -> 0
    ![image](https://github.com/user-attachments/assets/f9aa8036-bb90-48b4-841e-93a9f55bf2d3)

# III. x86-64 PROGRAM CORRECTNESS CHECKS
  1 . Example provided in project specs
    X1 -> 1.5
    X2 -> 3.0
    Y1 -> 4.0
    Y2 -> 2.0
    Z -> 2.5,
    ![image](https://github.com/user-attachments/assets/7721ba01-013c-4292-80a8-c9a486e0fac1)
    ![image](https://github.com/user-attachments/assets/9881a4f5-ccd1-45ff-ab06-b1b24791729a)
  2. Each value having the same large value (no distance hence 0)
    X1 -> 1000000
    X2 -> 1000000
    Y1 -> 1000000
    Y2 -> 1000000
    ![image](https://github.com/user-attachments/assets/75524394-9760-4eb9-8694-259d784d5960)
    ![image](https://github.com/user-attachments/assets/39e20ea0-4610-48a3-9ee1-dd9109b2a25a)

