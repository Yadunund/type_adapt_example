# type_adapt_example

In this branch we debug the performance of multiple type adapted subscriptions
in the same process with intra-process enabled.

## Compilation

Compile like any ROS 2 package.
This has been tested on ROS 2 Humble.

### Example 1: Publisher and Subscriptions handle `ROSCvMatContainer`

```
 ros2 launch type_adapt_example image_launch.py 
```

CPU usage for the component container is ~27%

### Example 2: Publisher handles `unique_ptr<ROSCvMatContainer>` and Subscriptions handles `<shared_ptr<const ROSCvMatContainer>`

```
 ros2 launch type_adapt_example image_pointer_launch.py 
```

CPU usage for the component container is ~0.3%
