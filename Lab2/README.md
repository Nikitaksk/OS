# 2nd Practice Task (OS)

The program showcases the usage of threads for concurrent execution and demonstrates basic array manipulation operations such as finding minimum and maximum values and calculating the average.

### Boost library: NO

### Run: `make`

### Some tests:

| Input                 | Expected Output                      | Output                                                                 | Is Output Correct? |
| --------------------- | ------------------------------------ | ---------------------------------------------------------------------- | ------------------ |
| 5<br>1 2 3 4 5        | Min: 1<br>Max: 5<br>Average: 3       | Min: 1<br>Max: 5<br>Average: 3<br>New array: 3 2 3 4 3                 | Yes                |
| 3<br>10 20 30         | Min: 10<br>Max: 30<br>Average: 20    | Min: 10<br>Max: 30<br>Average: 20<br>New array: 20 20 20               | Yes                |
| 6<br>5 10 15 20 25 30 | Min: 5<br>Max: 30<br>Average: 17.5   | Min: 5<br>Max: 30<br>Average: 17.5<br>New array: 17.5 10 15 20 25 17.5 | Yes                |
| 2<br>100 200          | Min: 100<br>Max: 200<br>Average: 150 | Min: 100<br>Max: 200<br>Average: 150<br>New array: 150 200             | Yes                |
| 4<br>8 8 8 8          | Min: 8<br>Max: 8<br>Average: 8       | Min: 8<br>Max: 8<br>Average: 8<br>New array: 8 8 8 8                   | Yes                |
| 1<br>0                | Min: 0<br>Max: 0<br>Average: 0       | Min: 0<br>Max: 0<br>Average: 0<br>New array: 0                         | Yes                |
