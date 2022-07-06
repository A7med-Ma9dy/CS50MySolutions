# DevOps Challenge

## The Goal
Your task is to set up ECS cluster and deploy a Kong Gateway, REST API and a frontend that consumes the REST API into it.

## The Process
1. Set up ECS cluster. However you like. We're leaving this purposefully open for you to do your own research on how you want to go about it.
1. When you have a running cluster, deploy (Kong Gateway)[https://konghq.com/kong-community-edition/], an API of your choice and a frontend application of your choice that consumes the API into the cluster. This can be a handwritten hello world application or any other ready-made docker images.
1. Now imagine you have multiple APIs needed to be deployed on the ECS cluster, please write a script to automate the creation of the APIs/ Frontend on ECS and Kong. 
1. Document how to access and use the applications you deployed

## Acceptance Criteria
* Your ECS cluster is up and running
* The frontend displays data from the API
* The code you've written to create the cluster and deploy the applications.

## Bonus Round (not required, but nice-to-have)
* Your frontend application is running and accessible under a domain of your choice
* Your application is available via SSL
* Automate the cluster setup, e.g. through cloudformation or terraform etc.
* Your application is auto-scaling. Meaning when you put load on it (via Apache Workbench for example) it automatically auto-scales horizontally by adding more pods
* Your API is hooked up to a database (can be inside the cluster or outside)
* You have isolated staging and production environments for your application

## How we're evaluating the result
Prioritised from most important to least important, here are our evaluation criteria:

1. Feature Completeness: Does your cluster fulfil all acceptance criteria?
1. Code Quality: If you've written any code to achieve the task, is the code clean, well-structured and easy to understand?
1. Documentation: How good is the documentation?
1. The extra mile: Did you hit any bonus goals?

