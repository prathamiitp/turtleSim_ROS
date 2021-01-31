#include<cmath>
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<iostream>
using namespace std;

class Polygon
{
private:
	const double kFrequency_ = 1;
	const int kMaxQueueSize_ = 1000;
	const double PI = 3.1415926535897;
	ros::NodeHandle nh_;
	ros::Publisher pub_;
	geometry_msgs::Twist msg_;
	double RadianAngleValue_;
public:
	void CalculationToFindAngleOfPolygon(double NumberOfSide);
	void PublishDataToCreatePolygon(float SideLength, bool toggle);
	void StreamMessege(int count);
	void DrawPolygon(double NumberOfSide, float SideLength, bool StreamMsg = true);
};

int main(int argc, char **argv)
{
	ros::init(argc,argv,"draw_polygon");
	cout << "specify the no. of sides and the side length(float) respectively \n";
	int NumberOfSide=0;
	float SideLength=0.0;
	cin >> NumberOfSide;
	cin >> SideLength;
	Polygon P;
	P.DrawPolygon(NumberOfSide, SideLength);
	ros::spin();
	return 0;
}

void Polygon::CalculationToFindAngleOfPolygon(double NumberOfSide)
{
	RadianAngleValue_ = (PI/180) * (360/NumberOfSide);
}

void Polygon::PublishDataToCreatePolygon(float SideLength, bool toggle)
{       
		if(toggle)
	{
		msg_.linear.x = 0;
		msg_.angular.z = RadianAngleValue_;		
	}
	else
	{
		msg_.linear.x = SideLength;
		msg_.angular.z = 0;		
	} 	
	
	pub_.publish(msg_);
}

void Polygon::StreamMessege(int count)
{
	ROS_INFO_STREAM("Sending " << "Linear = " << msg_.linear.x << " Angular = " << msg_.angular.z<<" "<<count);
}

void Polygon::DrawPolygon(double NumberOfSide, float SideLength, bool StreamMsg)
{
	pub_ = nh_.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",kMaxQueueSize_);
	int count=0;
	ros::Rate rate(kFrequency_);
	bool toggle = false;
	while(ros::ok())
	{
		if(count==1+(2*NumberOfSide))
		{
			break;
		}
		count++;
		toggle = !toggle;
		CalculationToFindAngleOfPolygon(NumberOfSide);
		PublishDataToCreatePolygon(SideLength, toggle);
		if(StreamMsg) StreamMessege(count);
		rate.sleep();
	}
}