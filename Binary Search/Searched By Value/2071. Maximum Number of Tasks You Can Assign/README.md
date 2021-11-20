# 2071. Maximum Number of Tasks You Can Assign

###### Tag: Bninary Search, Searched by Value

We could use binary search to guess the number(k) of tasks that the workers can complete. Since we are more concerning about the quantity of tasks, it is more reasonable to complete as much easy tasks as the workers can. The tasks array needs to be sorted so that we can keep track of the easiest k tasks. The assignment of worker strategy would be: The most difficult task in k number of tasks would be assigned to the worker with the most capability, if this worker can not complteted, we would assign a less capable worker with pill whose strength is most close to the difficulty of the task, if this worker can not complete the task, then it is impossible to complete the k number of tasks. 