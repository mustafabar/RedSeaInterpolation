
$INLINECOM { }


$ONTEXT


Sultan Albarakati
6/11/2018


$OFFTEXT


Sets


t          "time step" /t0*t200/
c          "the coordinate of the space" /x,y,z/
wp         "way points" /wy1*wy8/
se			 /1*66/
Sol 			/solv, mode, tim, ft/     

alias(t,tt);
alias(t,ttt);




$funclibin ff  '/home/albarass/RedSeaInterpolation/ocean_interpolation/build/wrapper/libwrapper.so'

* Define the function name
function cx   'Test function'  / ff.u/;
function cy   'Test function'  / ff.v/;
function cz   'Test function'  / ff.w/;
function g   'Test function'  / ff.charac /;

  

Scalars


amax       "maximal acceleration [m/s^2]"                     /1/   
Vmax       "maximal speed [m/s]"                              /1/ 
amax_z      "maximal acceleration in the z direction [m/s^2]"  /0.5/
Vmax_z     "maximal speed in the z direction [m/s]"           /0.15/
VmaxC                                                         /3/
dt                                                             /500/
pos_x0     "intial position in x direction"                   /638683/ 
pos_y0     "intial position in y direction"                   /1767854/
pos_z0     "intial position in z direction"                   /-700/
pos_xf     "intial position in x direction"                   /688182/ 
pos_yf     "intial position in y direction"                   /1721856/
pos_zf     "intial position in z direction"                   /-2/
V_x0       "intial position in x direction"                   /0/
V_y0       "intial position in y direction"                   /0/
V_z0       "intial position in z direction"                   /0/
SA         "current_Level"                                    /1/
cl                                                            /2/
ct                                                           /0.0/
stop                                                         /0.0/
min_tf                                                       /120/  
min_wp                                                       /55/;  


parameters

status(t,*)
h(t);


Variables

loss              "cost function- minmizing the time"
pos(c,t)          "position of the vehicle at step t"
V(c,t)            "velocity of the vehicle at step t"
a(c,t)            "the acceleration at step t"
f(t)
u_x(t)
u_y(t)
u_z(t);

Positive variables
tf;


Equations
fobj,
fobj2,
current_x,
current_y,
current_z,
equality_dyanmic_position_x,
equality_dyanmic_position_y,
equality_dyanmic_position_ux,
equality_dyanmic_position_uy,
equality_dyanmic_position_z,
equality_dyanmic_position_uz,
equality_dyanmic_velocity,
inq_acceleration_timet,
inq_velocity_timet,
inq_acceleration_timet_z,
inq_velocity_timet_z,
Obs_constraint,
Obs_constraint1,
arrival_constarint,
final_time;


fobj..                                                                                  loss =e= tf;

fobj2..                                                                                 loss =e= 1;

current_x(t)..                                                                          u_x(t) =e= cl * cx(pos('x',t),pos('y',t),pos('z',t));

current_y(t)..                                                                          u_y(t) =e= cl * cy(pos('x',t),pos('y',t),pos('z',t));

current_z(t)..                                                                          u_z(t) =e= cl * cz(pos('x',t),pos('y',t),pos('z',t));

equality_dyanmic_position_x(c,t)  $(ORD(t) LT CARD(t) AND ORD(c) EQ 1)..                pos(c,t+1)=e= pos(c,t) + V(c,t)*dt + 0.5*a(c,t)*dt*dt ;

equality_dyanmic_position_y(c,t)  $(ORD(t) LT CARD(t) AND ORD(c) EQ 2)..                pos(c,t+1)=e= pos(c,t) + V(c,t)*dt + 0.5*a(c,t)*dt*dt ;

equality_dyanmic_position_z(c,t) $(ORD(t) LT CARD(t) AND ORD(c) EQ 3).. 		pos(c,t+1)=e= pos(c,t) + V(c,t)*dt + 0.5*a(c,t)*dt*dt ;


equality_dyanmic_position_ux(c,t)  $(ORD(t) LT CARD(t) AND ORD(c) EQ 1)..                pos(c,t+1)=e= pos(c,t) + V(c,t)*dt + 0.5*a(c,t)*dt*dt + u_x(t)*dt;

equality_dyanmic_position_uy(c,t)  $(ORD(t) LT CARD(t) AND ORD(c) EQ 2)..                pos(c,t+1)=e= pos(c,t) + V(c,t)*dt + 0.5*a(c,t)*dt*dt + u_y(t)*dt;

equality_dyanmic_position_uz(c,t) $(ORD(t) LT CARD(t) AND ORD(c) EQ 3).. 		 pos(c,t+1)=e= pos(c,t) + V(c,t)*dt + 0.5*a(c,t)*dt*dt + u_z(t)*dt;

equality_dyanmic_velocity(c,t) $(ORD(t) LT CARD(t))..	                                 V(c,t+1)=e= V(c,t)+a(c,t)*dt;

inq_acceleration_timet(t)..                                                             a('x',t)*a('x',t)+ a('y',t)*a('y',t) =l= amax*amax ;

inq_acceleration_timet_z(t)..                                                           a('z',t)*a('z',t)=l=amax_z*amax_z;

inq_velocity_timet(t)..                                                                 V('x',t)*V('x',t)+V('y',t)*V('y',t) =l= Vmax*Vmax ;

inq_velocity_timet_z(t)..                                                               V('z',t)*V('z',t)=l=Vmax_z*Vmax_z;

Obs_constraint(t)..                                                                     f(t) =e= g(pos('x',t),pos('y',t),pos('z',t));

Obs_constraint1(t)..                                                                    f(t) =g= 0;


final_time.. 										tf =e= sum(t, h(t)*dt*(ord(t)-1));



pos.lo('x',t)=635500;
pos.lo('y',t)=1708032;
pos.lo('z',t)=-2234;
pos.up('x',t)=697772;
pos.up('y',t)=1770400;
pos.up('z',t)=-2;


pos.fx('x','t0')=pos_x0;
pos.fx('y','t0')=pos_y0;
pos.fx('z','t0')=pos_z0;

pos.fx('x','t93')=642954;
pos.fx('y','t93')=1722191;
pos.fx('z','t93')=-600;


V.lo(c,t)=-3;
V.up(c,t)=3;

V.fx('x','t0')=V_x0;
V.fx('y','t0')=V_y0;
V.fx('z','t0')=V_z0;



u_x.lo(t) = -VmaxC;
u_x.up(t) = VmaxC;
u_y.lo(t) = -VmaxC;
u_y.up(t) = VmaxC;


a.lo(c,t)=-amax;
a.up(c,t)=amax;


f.lo(t)= -2;
f.up(t)= 2;


model path_planning0          /
fobj2,
equality_dyanmic_position_x,
equality_dyanmic_position_y,
equality_dyanmic_position_z,
equality_dyanmic_velocity,
inq_acceleration_timet,
inq_velocity_timet,
inq_acceleration_timet_z,
inq_velocity_timet_z,
Obs_constraint,
Obs_constraint1,
final_time/;

path_planning0.reslim  = 1000;


OPTIONS
OPTCR = 0.0
OPTCA = 0.0
*NLP = IPOPT;
*NLP = Knitro;
NLP = conopt;
*MINLP= SBB;


option domlim = 5;


Parameters

h(t)
hd(se)  'model handles'
par(se,Sol)
n_pos0(c,t)
n_V0(c,t)
n_a0(c,t)
n_tf(t);

scalar
BIGTF0
best_se;


path_planning0.solveLink = 3;

h(t) = 0;



pos.lo('x',t)=635500;
pos.lo('y',t)=1708032;
pos.lo('z',t)=-2234;
pos.up('x',t)=697772;
pos.up('y',t)=1770400;
pos.up('z',t)=-2;


pos.fx('x','t0')=pos_x0;
pos.fx('y','t0')=pos_y0;
pos.fx('z','t0')=pos_z0;

pos.fx('x','t93')=642954;
pos.fx('y','t93')=1722191;
pos.fx('z','t93')=-600;


file wdata /ini_ex2_b_1_wp2.csv/;
*wdata2.ap = 1; {Flag to turn the append option on for the file with pointer wdata.}
wdata.pc = 5; {CSV format definition to export to Excel}
wdata.pw = 1000; {Used to specify the number of columns (characters) which can be placed on a single row of the page}

loop(se,
     loop( t $(ORD(T) EQ ORD(se)+ min_tf),
        h(t)=1;

pos.lo('x',t)=pos_xf-dt;
pos.lo('y',t)=pos_yf-dt;
pos.lo('z',t)=-3;
pos.up('x',t)=pos_xf+dt;
pos.up('y',t)=pos_yf+dt;
pos.up('z',t)=-2;


     display  h;
     display 'sultan';
);


solve path_planning0 using NLP minimizing loss;

hd(se) = path_planning0.handle;

h(t)=0;

pos.lo('x',t)=635500;
pos.lo('y',t)=1708032;
pos.lo('z',t)=-2234;

pos.up('x',t)=697772;
pos.up('y',t)=1770400;
pos.up('z',t)=-2;

pos.fx('x','t0')=pos_x0;
pos.fx('y','t0')=pos_y0;
pos.fx('z','t0')=pos_z0;

pos.fx('x','t93')=642954;
pos.fx('y','t93')=1722191;
pos.fx('z','t93')=-600;

);
BIGTF0 = 1e9;
repeat
   loop(se$(hd(se)),

   if(handleStatus(hd(se)) = 2,

   path_planning0.handle = hd(se);

   execute_loadhandle path_planning0;

   Par(se,'solv')= path_planning0.solvestat; 

   Par(se,'mode')= path_planning0.modelstat;

   Par(se,'tim')= path_planning0.resusd;

   Par(se,'ft')= tf.l/dt;


if ( path_planning0.modelstat EQ 2 and path_planning0.solvestat EQ 1,

if(Par(se,'ft') < BIGTF0,
	BIGTF0 = Par(se,'ft');
	best_se=ord(se);

     n_pos0(c,t) = pos.l(c,t);
       n_V0(c,t) = V.l(c,t);
       n_a0(c,t) = a.l(c,t);
          
	put wdata;
       loop(t,
	   put t.tl, 
	   loop(c, put  n_pos0(c,t) );
	   loop(c, put n_v0(c,t));
	   loop(c, put n_a0(c,t));

	   put /;
       );
       putclose wdata;

);	   
);	
   display$handleDelete(hd(se)) 'trouble deleting handles' ;
   hd(se) = 0;        
   ) ;
);
   until card(hd) = 0   or timeelapsed > 3000;



display  Par,best_se,n_pos0,n_V0,n_a0,BIGTF0;
 

pos.lo('x',t)=635500;
pos.lo('y',t)=1708032;
pos.lo('z',t)=-2234;
pos.up('x',t)=697772;
pos.up('y',t)=1770400;
pos.up('z',t)=-2;
pos.fx('x','t0')=pos_x0;
pos.fx('y','t0')=pos_y0;
pos.fx('z','t0')=pos_z0;


pos.fx('x','t0')=pos_x0;
pos.fx('y','t0')=pos_y0;
pos.fx('z','t0')=pos_z0;


V.lo(c,t)=-3;
V.up(c,t)=3;

V.fx('x','t0')=V_x0;
V.fx('y','t0')=V_y0;
V.fx('z','t0')=V_z0;



u_x.lo(t) = -VmaxC;
u_x.up(t) = VmaxC;
u_y.lo(t) = -VmaxC;
u_y.up(t) = VmaxC;


a.lo(c,t)=-amax;
a.up(c,t)=amax;

f.lo(t)= -2;
f.up(t)= 2;



pos.l(c,t)= n_pos0(c,t);
V.l(c,t) = n_v0(c,t);
a.l(c,t) = n_a0(c,t) ;

f.l(t) = g(pos.l('x',t),pos.l('y',t),pos.l('z',t));
u_x.l(t)= cl*cx(pos.l('x',t),pos.l('y',t),pos.l('z',t));
u_y.l(t)= cl*cy(pos.l('x',t),pos.l('y',t),pos.l('z',t));
u_z.l(t)= cl*cz(pos.l('x',t),pos.l('y',t),pos.l('z',t));

u_x.lo(t) = -VmaxC;
u_x.up(t) = VmaxC;
u_y.lo(t) = -VmaxC;
u_y.up(t) = VmaxC;


a.lo(c,t)=-amax;
a.up(c,t)=amax;

f.lo(t)= -2;
f.up(t)= 2;


model path_planning2          /
fobj2,
current_x,
current_y,
current_z,
equality_dyanmic_position_ux,
equality_dyanmic_position_uy,
equality_dyanmic_position_uz,
equality_dyanmic_velocity,
inq_acceleration_timet,
inq_velocity_timet,
inq_acceleration_timet_z,
inq_velocity_timet_z,
Obs_constraint,
Obs_constraint1,
final_time/;





OPTIONS
OPTCR = 0.0
OPTCA = 0.0
*NLP = IPOPT;
NLP = conopt;
*MINLP = BARON;
*MINLP= SBB;


option domlim = 5;


path_planning2.reslim  = 3000;



Parameters

 h(t)
 hd(se)  'model handles'
 par(se,Sol)
 n_pos(c,t)
 n_V(c,t)
 n_a(c,t)
 n_cx(t)
 n_cy(t)
 n_cz(t);

scalar
BIGTF
best_se;



file wdata2 /current_ex2_b_1_wp2.csv/;
*wdata2.ap = 1; {Flag to turn the append option on for the file with pointer wdata.}
wdata2.pc = 5; {CSV format definition to export to Excel}
wdata2.pw = 1000; {Used to specify the number of columns (characters) which can be placed on a single row of the page}

path_planning2.solveLink = 3;

h(t) = 0;

loop(se,
     loop( t $ (ORD(T) EQ ORD(se)+ min_tf),
            h(t)=1;
	 
	    pos.lo('x',t)=pos_xf-dt;
	    pos.lo('y',t)=pos_yf-dt;
	    pos.lo('z',t)=-3;
	    pos.up('x',t)=pos_xf+dt;
	    pos.up('y',t)=pos_yf+dt;
	    pos.up('z',t)=-2;

     display  h;
     display 'sultan';
);

solve path_planning2 using NLP minimizing loss;

hd(se) = path_planning2.handle;

h(t)=0;

pos.lo('x',t)=635500;
pos.lo('y',t)=1708032;
pos.lo('z',t)=-2234;
pos.up('x',t)=697772;
pos.up('y',t)=1770400;
pos.up('z',t)=-2;
pos.fx('x','t0')=pos_x0;
pos.fx('y','t0')=pos_y0;
pos.fx('z','t0')=pos_z0;


);
BIGTF = 1e9;
repeat
   loop(se$(hd(se)),

   if(handleStatus(hd(se)) = 2,

   path_planning2.handle = hd(se);

   execute_loadhandle path_planning2;

   Par(se,'solv')= path_planning2.solvestat; 

   Par(se,'mode')= path_planning2.modelstat;

   Par(se,'tim')= path_planning2.resusd;

   Par(se,'ft')= tf.l/dt;


if ( path_planning2.modelstat EQ 2 and path_planning2.solvestat EQ 1,

if(Par(se,'ft') < BIGTF,
	BIGTF = Par(se,'ft');
	best_se=ord(se);

     n_pos(c,t) = pos.l(c,t);
       n_V(c,t) = V.l(c,t);
       n_a(c,t) = a.l(c,t);
       n_cx(t) = u_x.l(t);
       n_cy(t) = u_y.l(t);
       n_cz(t) = u_z.l(t);
          


);	   
);	
   display$handleDelete(hd(se)) 'trouble deleting handles' ;
   hd(se) = 0;        
   ) ;
);
   until card(hd) = 0   or timeelapsed > 5000;


	put wdata2;
       loop(t,
	   put t.tl, 
	   loop(c, put  n_pos(c,t) );
	   loop(c, put n_v(c,t));
	   loop(c, put n_a(c,t));
                   put  n_cx(t);
                   put  n_cy(t);
                   put  n_cz(t);
	   put /;
       );
       putclose wdata2;

display  Par,best_se,n_pos,n_V,n_a, n_cx, n_cy, n_cz,BIGTF;
