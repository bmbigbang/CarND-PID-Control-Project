# CarND-Controls-PID

In order to optimise the PID parameters, manual tuning was performed to 
observe and optimise the damped oscillation model. Initially, the speed was kept
constant, and the linear proportional gain only was considered to keep oscillations
around the zero cross track error. This term was adjusted to observe the car driving
in the central position on the road, where the cross track error is near zero.

This linear term is also responsible for the responsiveness of the car's steering to the
road angle and may need to be adjusted if steering around the curviest bends is not
happening in a timely fashion. Unfortunately this term also heavily depends on the
speed and acceleration of the vehicle which is also affecting the vehicle's position
as time goes on. Therefore more proportional terms will need to be implemented for 
PID controller steering value calculation which holds the contributions of speed
and acceleration towards the steering angle. For the sake of simplicity, the speed was kept constant by a limitation on the throttle value.

Next, the differential term of the PID controller was adjusted such as to observe the cars oscillatory behaviour become a gradual damping towards zero while keeping the other
terms constant. This term allows the PID controller to steer the car towards the centre
based on the recent changes to the cross track error. The approach is similar to a 
Gradient Decent calculation and can be improved upon by calculating a local history
of gradients of the cross track error.

Finally, the integral term of the PID controller was adjusted such as to improve
the damping term for secondary oscillatory behaviour near the zero cross track error 
(centre of the road). This term is responsible for improving the damping of the oscillation
to become critical damping by means of measuring the sum of the cross track errors
in recent history, and can be thought off as an offset that has no contribution
in the local cross track error gradients' space.


