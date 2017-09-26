#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "first_marker");
  ros::init(argc, argv, "second_marker");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub_one = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  while (ros::ok())
  {
    visualization_msgs::Marker marker_one;
    visualization_msgs::Marker marker_two;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker_one.header.frame_id = "/my_frame";
    marker_one.header.stamp = ros::Time::now();

    marker_two.header.frame_id = "/my_frame";
    marker_two.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker_one.ns = "first marker";
    marker_one.id = 0;

    marker_two.ns = "second_marker";
    marker_two.id = 1;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker_one.type = shape;
    marker_two.type = shape;
    shape = visualization_msgs::Marker::CUBE;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker_one.action = visualization_msgs::Marker::ADD;
    marker_two.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker_one.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker_one.pose.position.x = 1;
    marker_one.pose.position.y = 0;
    marker_one.pose.position.z = 0;
    marker_one.pose.orientation.x = 0.0;
    marker_one.pose.orientation.y = 0.0;
    marker_one.pose.orientation.z = 0.0;
    marker_one.pose.orientation.w = 0.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker_one.scale.x = 1.0;
    marker_one.scale.y = 1.0;
    marker_one.scale.z = 1.0;

    // Set the color -- be sure to set alpha to something non-zero!
    marker_one.color.r = 0.0f;
    marker_one.color.g = 1.0f;
    marker_one.color.b = 0.0f;
    marker_one.color.a = 1.0;

    // Set the pose of the marker_one.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker_two.pose.position.x = 3;
    marker_two.pose.position.y = 0;
    marker_two.pose.position.z = 0;
    marker_two.pose.orientation.x = 0.0;
    marker_two.pose.orientation.y = 0.0;
    marker_two.pose.orientation.z = 0.0;
    marker_two.pose.orientation.w = 0.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker_two.scale.x = 1.0;
    marker_two.scale.y = 1.0;
    marker_two.scale.z = 1.0;

    // Set the color -- be sure to set alpha to something non-zero!
    marker_two.color.r = 0.0f;
    marker_two.color.g = 1.0f;
    marker_two.color.b = 0.0f;
    marker_two.color.a = 1.0;


    marker_one.lifetime = ros::Duration();
    marker_two.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub_one.getNumSubscribers())
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    marker_pub_one.publish(marker_one);
    marker_pub_two.publish(marker_two);
  }

}    