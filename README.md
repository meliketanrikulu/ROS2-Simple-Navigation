# ROS2-Simple-Navigation

### Dependencies
* Ubuntu 20.04
* ROS2 Foxy

### Package Description
This package contains a simple publisher application of the /nav_msgs/Path message type with ROS2-Foxy. 136 different paths are created by scanning with 2 degree differences between 0-270 degrees. The coordinates that define the positions of each Pose in the path is
given by following function:

``
x = 15*cos(θ) ``
``
y = 0.5*15*sin(θ)
``
``
z = 0
``
###### Message header frame_id: ``/map`` is selected. Topic name is ``path_ellipse_partial``. 
* ``$ ros2 topic list``
<img src="/img/topic_list.png" alt="topic_list"/>

* `` $ ros2 topic echo /path_ellipse_partial ``
<img src="/img/topic_echo.png" alt="My cool logo"/>

### Install and Run Navigation Package 
###### Install the package to your workspace 
* `cd ~/<your_workspace>/src/`
* ``$ git clone git@github.com:meliketanrikulu/ROS2-Simple-Navigation.git``
###### Compile your package
* ``cd ..``
* ``colcon build --packages-select navigation``
###### Run publisher node
* ``ros2 run navigation publisher``

### Visualization in RViz2
The resulting path is published over the /path_ellipse_partial topic. Click Add, select the message of type path publishing from the topic /path ellips_partial published in the By Topic tab. You are expected to see the following result.

<img src="/img/elips1.png" alt="RESULT"/>


### Resources
* https://docs.ros.org/en/foxy/Tutorials/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html#write-the-publisher-node
* https://docs.ros.org/en/foxy/Installation/Ubuntu-Install-Debians.html
* http://docs.ros.org/en/noetic/api/nav_msgs/html/msg/Path.html
* https://docs.ros.org/en/foxy/Tutorials/Workspace/Creating-A-Workspace.html
* https://docs.ros.org/en/foxy/Tutorials/Creating-Your-First-ROS2-Package.html
