## QUESTION 1
![image](https://github.com/user-attachments/assets/c0686361-8e6c-4846-9e5b-8a7182a369f9)

## QUESTION 1A
![image](https://github.com/user-attachments/assets/ff3b6503-8d84-4b8d-bf1e-44d582fc1322)

## QUESTION 2A
![image](https://github.com/user-attachments/assets/d17ae840-bedc-47d4-946a-373993414f01)

**DRY RUNN**

| Step | Process     | Code / Action                              | Output / Effect                        |
|------|-------------|---------------------------------------------|----------------------------------------|
| 1    | Parent      | `main()` starts                             | —                                      |
| 2    | Parent      | `signal(SIGCHLD, proc_exit);`               | Registers `proc_exit` as SIGCHLD handler |
| 3    | Parent + Child | `fork()` called                          | Creates a child process                |
| 4    | Child       | `case 0:` branch                            | Child enters its code block            |
| 5    | Child       | `printf("I'm alive...")`                    | `I'm alive (temporarily)`              |
| 6    | Child       | `ret_code = rand();` (e.g., 83)             | Generates random return code           |
| 7    | Child       | `printf("Return code is %d", ret_code);`   | `Return code is 83`                    |
| 8    | Child       | `exit(ret_code);`                           | Child exits, sends SIGCHLD to parent   |
| 9    | Parent      | `pause();`                                  | Suspends until signal (SIGCHLD) arrives |
| 10   | Parent      | SIGCHLD received → `proc_exit()` runs       | Signal handler activated               |
| 11   | Parent      | `wait3(&wstat, WNOHANG, NULL)`              | Reaps child process                    |
| 12   | Parent      | `printf("Return code: %d", wstat);`         | `Return code: 21248` (example)         |
| 13   | Parent      | `wait3()` returns 0                         | No more children                       |
| 14   | Parent      | `printf("return value of wait3() is 0");`   | `return value of wait3() is 0`         |
| 15   | Parent      | `proc_exit()` returns → back to `pause()`   | —                                      |
| 16   | Parent      | `exit(0);`                                  | Program ends                           |

## QUESTION 2B
![image](https://github.com/user-attachments/assets/9be41fbf-b02f-41cf-96a9-9169449f36c1)

## QUESTION 3A
![image](https://github.com/user-attachments/assets/e4c1d054-1398-4290-abd1-4d1491021a91)

## QUESTION 3C
![image](https://github.com/user-attachments/assets/866d4160-0f6d-4d18-ac51-83a4b0e49844)
