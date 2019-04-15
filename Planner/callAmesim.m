%%
% % % add Amesim Model
  addpath(fullfile(getenv('AME'),'scripting','matlab','amesim'));
  ! AMECirChecker -g -q --nobackup --nologfile DoubleLaneChange.ame
% % % 
% % % % Open system in test directory
  ! AMELoad DoubleLaneChange.ame
% % % 
% % % % Store the circuit name in a variable
 sname='DoubleLaneChange';

%get the 70 states of the car 

%CAR STATE PARAMETERS 
%%
car_param.vG_1           =   char(amegetparamnamefromui(sname,'vG_1@Chassis15dof_32ports'));
car_param.vG_2           =   char(amegetparamnamefromui(sname,'vG_2@Chassis15dof_32ports'));
car_param.vG_3           =   char(amegetparamnamefromui(sname,'vG_3@Chassis15dof_32ports'));
%%
car_param.OG_1           =   char(amegetparamnamefromui(sname,'OG_1@Chassis15dof_32ports'));
car_param.OG_2           =   char(amegetparamnamefromui(sname,'OG_2@Chassis15dof_32ports'));
car_param.OG_3           =   char(amegetparamnamefromui(sname,'OG_3@Chassis15dof_32ports'));
%%
car_param.omeg_1         =   char(amegetparamnamefromui(sname,'omeg_1@Chassis15dof_32ports'));
car_param.omeg_2         =   char(amegetparamnamefromui(sname,'omeg_2@Chassis15dof_32ports'));
car_param.omeg_3         =   char(amegetparamnamefromui(sname,'omeg_3@Chassis15dof_32ports'));
%%
car_param.Eulerangle_1   =   char(amegetparamnamefromui(sname,'Eulerangle_1@Chassis15dof_32ports'));
car_param.Eulerangle_2   =   char(amegetparamnamefromui(sname,'Eulerangle_2@Chassis15dof_32ports'));
car_param.Eulerangle_3   =   char(amegetparamnamefromui(sname,'Eulerangle_3@Chassis15dof_32ports'));
%%
% 11 Front Left
car_param.vzrelavg       =   char(amegetparamnamefromui(sname,'vzrelavg@Chassis15dof_32ports'));
car_param.zrelavg        =   char(amegetparamnamefromui(sname,'zrelavg@Chassis15dof_32ports'));
car_param.Wrelavg        =   char(amegetparamnamefromui(sname,'Wrelavg@Chassis15dof_32ports'));
car_param.thetarelavg    =   char(amegetparamnamefromui(sname,'thetarelavg@Chassis15dof_32ports'));
%%
% 12 Front Right
car_param.vzrelavd       =   char(amegetparamnamefromui(sname,'vzrelavd@Chassis15dof_32ports'));
car_param.zrelavd        =   char(amegetparamnamefromui(sname,'zrelavd@Chassis15dof_32ports'));
car_param.Wrelavd        =   char(amegetparamnamefromui(sname,'Wrelavd@Chassis15dof_32ports'));
car_param.thetarelavd    =   char(amegetparamnamefromui(sname,'thetarelavd@Chassis15dof_32ports'));
%%
% 21 Rear Left
car_param.vzrelarrg      =   char(amegetparamnamefromui(sname,'vzrelarrg@Chassis15dof_32ports'));
car_param.zrelarrg       =   char(amegetparamnamefromui(sname,'zrelarrg@Chassis15dof_32ports'));
car_param.Wrelarrg       =   char(amegetparamnamefromui(sname,'Wrelarrg@Chassis15dof_32ports'));
car_param.thetarelarrg   =   char(amegetparamnamefromui(sname,'thetarelarrg@Chassis15dof_32ports'));
% 22 Rear Right
car_param.vzrelarrd      =   char(amegetparamnamefromui(sname,'vzrelarrd@Chassis15dof_32ports'));
car_param.zrelarrd       =   char(amegetparamnamefromui(sname,'zrelarrd@Chassis15dof_32ports'));
car_param.Wrelarrd       =   char(amegetparamnamefromui(sname,'Wrelarrd@Chassis15dof_32ports'));
car_param.thetarelarrd   =   char(amegetparamnamefromui(sname,'thetarelarrd@Chassis15dof_32ports'));
%%
car_param.vycrav         =   char(amegetparamnamefromui(sname,'vycrav@Chassis15dof_32ports'));
car_param.ycrav          =   char(amegetparamnamefromui(sname,'ycrav@Chassis15dof_32ports'));
%% ELECTRO 11 FRONT LEFT
car_param.WelastoR1_1_FL =   char(amegetparamnamefromui(sname,'WelastoR1_1@Elastokinematics'));
car_param.WelastoR1_2_FL =   char(amegetparamnamefromui(sname,'WelastoR1_2@Elastokinematics'));
car_param.WelastoR1_3_FL =   char(amegetparamnamefromui(sname,'WelastoR1_3@Elastokinematics'));
%%
car_param.THETAelastoR1_1_FL =   char(amegetparamnamefromui(sname,'THETAelastoR1_1@Elastokinematics'));
car_param.THETAelastoR1_2_FL =   char(amegetparamnamefromui(sname,'THETAelastoR1_2@Elastokinematics'));
car_param.THETAelastoR1_3_FL =   char(amegetparamnamefromui(sname,'THETAelastoR1_3@Elastokinematics'));
%%
car_param.VxelastoR1_FL =   char(amegetparamnamefromui(sname,'VxelastoR1@Elastokinematics'));
car_param.VyelastoR1_FL =   char(amegetparamnamefromui(sname,'VyelastoR1@Elastokinematics'));
car_param.XelastoR1_FL  =   char(amegetparamnamefromui(sname,'XelastoR1@Elastokinematics'));
car_param.YelastoR1_FL  =   char(amegetparamnamefromui(sname,'YelastoR1@Elastokinematics'));
%%
%% ELECTRO 12 FRONT RIGHT
car_param.WelastoR1_1_FR =   char(amegetparamnamefromui(sname,'WelastoR1_1@Elastokinematics_2'));
car_param.WelastoR1_2_FR =   char(amegetparamnamefromui(sname,'WelastoR1_2@Elastokinematics_2'));
car_param.WelastoR1_3_FR =   char(amegetparamnamefromui(sname,'WelastoR1_3@Elastokinematics_2'));
%%
car_param.THETAelastoR1_1_FR =   char(amegetparamnamefromui(sname,'THETAelastoR1_1@Elastokinematics_2'));
car_param.THETAelastoR1_2_FR =   char(amegetparamnamefromui(sname,'THETAelastoR1_2@Elastokinematics_2'));
car_param.THETAelastoR1_3_FR =   char(amegetparamnamefromui(sname,'THETAelastoR1_3@Elastokinematics_2'));
%%
car_param.VxelastoR1_FR =   char(amegetparamnamefromui(sname,'VxelastoR1@Elastokinematics_2'));
car_param.VyelastoR1_FR =   char(amegetparamnamefromui(sname,'VyelastoR1@Elastokinematics_2'));
car_param.XelastoR1_FR  =   char(amegetparamnamefromui(sname,'XelastoR1@Elastokinematics_2'));
car_param.YelastoR1_FR  =   char(amegetparamnamefromui(sname,'YelastoR1@Elastokinematics_2'));
%%
%% ELECTRO 21 Rear LEFT
car_param.WelastoR1_1_RL =   char(amegetparamnamefromui(sname,'WelastoR1_1@Elastokinematics_2_2'));
car_param.WelastoR1_2_RL =   char(amegetparamnamefromui(sname,'WelastoR1_2@Elastokinematics_2_2'));
car_param.WelastoR1_3_RL =   char(amegetparamnamefromui(sname,'WelastoR1_3@Elastokinematics_2_2'));
%%
car_param.THETAelastoR1_1_RL =   char(amegetparamnamefromui(sname,'THETAelastoR1_1@Elastokinematics_2_2'));
car_param.THETAelastoR1_2_RL =   char(amegetparamnamefromui(sname,'THETAelastoR1_2@Elastokinematics_2_2'));
car_param.THETAelastoR1_3_RL =   char(amegetparamnamefromui(sname,'THETAelastoR1_3@Elastokinematics_2_2'));
%%
car_param.VxelastoR1_RL =   char(amegetparamnamefromui(sname,'VxelastoR1@Elastokinematics_2_2'));
car_param.VyelastoR1_RL =   char(amegetparamnamefromui(sname,'VyelastoR1@Elastokinematics_2_2'));
car_param.XelastoR1_RL  =   char(amegetparamnamefromui(sname,'XelastoR1@Elastokinematics_2_2'));
car_param.YelastoR1_RL  =   char(amegetparamnamefromui(sname,'YelastoR1@Elastokinematics_2_2'));
%%
%% ELECTRO 21 Rear LEFT
car_param.WelastoR1_1_RR =   char(amegetparamnamefromui(sname,'WelastoR1_1@Elastokinematics_3'));
car_param.WelastoR1_2_RR =   char(amegetparamnamefromui(sname,'WelastoR1_2@Elastokinematics_3'));
car_param.WelastoR1_3_RR =   char(amegetparamnamefromui(sname,'WelastoR1_3@Elastokinematics_3'));
%%
car_param.THETAelastoR1_1_RR =   char(amegetparamnamefromui(sname,'THETAelastoR1_1@Elastokinematics_3'));
car_param.THETAelastoR1_2_RR =   char(amegetparamnamefromui(sname,'THETAelastoR1_2@Elastokinematics_3'));
car_param.THETAelastoR1_3_RR =   char(amegetparamnamefromui(sname,'THETAelastoR1_3@Elastokinematics_3'));
%%
car_param.VxelastoR1_RR =   char(amegetparamnamefromui(sname,'VxelastoR1@Elastokinematics_3'));
car_param.VyelastoR1_RR =   char(amegetparamnamefromui(sname,'VyelastoR1@Elastokinematics_3'));
car_param.XelastoR1_RR  =   char(amegetparamnamefromui(sname,'XelastoR1@Elastokinematics_3'));
car_param.YelastoR1_RR  =   char(amegetparamnamefromui(sname,'YelastoR1@Elastokinematics_3'));
%%

%CAR STATE VARIABLES
%%
car_var.vG_1           =   char(amegetvarnamefromui(sname,'vG_1@Chassis15dof_32ports'));
car_var.vG_2           =   char(amegetvarnamefromui(sname,'vG_2@Chassis15dof_32ports'));
car_var.vG_3           =   char(amegetvarnamefromui(sname,'vG_3@Chassis15dof_32ports'));
%%
car_var.OG_1           =   char(amegetvarnamefromui(sname,'OG_1@Chassis15dof_32ports'));
car_var.OG_2           =   char(amegetvarnamefromui(sname,'OG_2@Chassis15dof_32ports'));
car_var.OG_3           =   char(amegetvarnamefromui(sname,'OG_3@Chassis15dof_32ports'));
%%
car_var.omeg_1         =   char(amegetvarnamefromui(sname,'omeg_1@Chassis15dof_32ports'));
car_var.omeg_2         =   char(amegetvarnamefromui(sname,'omeg_2@Chassis15dof_32ports'));
car_var.omeg_3         =   char(amegetvarnamefromui(sname,'omeg_3@Chassis15dof_32ports'));
%%
car_var.Eulerangle_1   =   char(amegetvarnamefromui(sname,'Eulerangle_1@Chassis15dof_32ports'));
car_var.Eulerangle_2   =   char(amegetvarnamefromui(sname,'Eulerangle_2@Chassis15dof_32ports'));
car_var.Eulerangle_3   =   char(amegetvarnamefromui(sname,'Eulerangle_3@Chassis15dof_32ports'));
%%
% 11 Front Left
car_var.vzrelavg       =   char(amegetvarnamefromui(sname,'vzrelavg@Chassis15dof_32ports'));
car_var.zrelavg        =   char(amegetvarnamefromui(sname,'zrelavg@Chassis15dof_32ports'));
car_var.Wrelavg        =   char(amegetvarnamefromui(sname,'Wrelavg@Chassis15dof_32ports'));
car_var.thetarelavg    =   char(amegetvarnamefromui(sname,'thetarelavg@Chassis15dof_32ports'));
%%
% 12 Front Right
car_var.vzrelavd       =   char(amegetvarnamefromui(sname,'vzrelavd@Chassis15dof_32ports'));
car_var.zrelavd        =   char(amegetvarnamefromui(sname,'zrelavd@Chassis15dof_32ports'));
car_var.Wrelavd        =   char(amegetvarnamefromui(sname,'Wrelavd@Chassis15dof_32ports'));
car_var.thetarelavd    =   char(amegetvarnamefromui(sname,'thetarelavd@Chassis15dof_32ports'));
%%
% 21 Rear Left
car_var.vzrelarrg      =   char(amegetvarnamefromui(sname,'vzrelarrg@Chassis15dof_32ports'));
car_var.zrelarrg       =   char(amegetvarnamefromui(sname,'zrelarrg@Chassis15dof_32ports'));
car_var.Wrelarrg       =   char(amegetvarnamefromui(sname,'Wrelarrg@Chassis15dof_32ports'));
car_var.thetarelarrg   =   char(amegetvarnamefromui(sname,'thetarelarrg@Chassis15dof_32ports'));
% 22 Rear Right
car_var.vzrelarrd      =   char(amegetvarnamefromui(sname,'vzrelarrd@Chassis15dof_32ports'));
car_var.zrelarrd       =   char(amegetvarnamefromui(sname,'zrelarrd@Chassis15dof_32ports'));
car_var.Wrelarrd       =   char(amegetvarnamefromui(sname,'Wrelarrd@Chassis15dof_32ports'));
car_var.thetarelarrd   =   char(amegetvarnamefromui(sname,'thetarelarrd@Chassis15dof_32ports'));
%%
car_var.vycrav         =   char(amegetvarnamefromui(sname,'vycrav@Chassis15dof_32ports'));
car_var.ycrav          =   char(amegetvarnamefromui(sname,'ycrav@Chassis15dof_32ports'));
%%
%% ELECTRO 11 FRONT LEFT
car_var.WelastoR1_1_FL =   char(amegetvarnamefromui(sname,'WelastoR1_1@Elastokinematics'));
car_var.WelastoR1_2_FL =   char(amegetvarnamefromui(sname,'WelastoR1_2@Elastokinematics'));
car_var.WelastoR1_3_FL =   char(amegetvarnamefromui(sname,'WelastoR1_3@Elastokinematics'));
%%
car_var.THETAelastoR1_1_FL =   char(amegetvarnamefromui(sname,'THETAelastoR1_1@Elastokinematics'));
car_var.THETAelastoR1_2_FL =   char(amegetvarnamefromui(sname,'THETAelastoR1_2@Elastokinematics'));
car_var.THETAelastoR1_3_FL =   char(amegetvarnamefromui(sname,'THETAelastoR1_3@Elastokinematics'));
%%
car_var.VxelastoR1_FL =   char(amegetvarnamefromui(sname,'VxelastoR1@Elastokinematics'));
car_var.VyelastoR1_FL =   char(amegetvarnamefromui(sname,'VyelastoR1@Elastokinematics'));
car_var.XelastoR1_FL  =   char(amegetvarnamefromui(sname,'XelastoR1@Elastokinematics'));
car_var.YelastoR1_FL  =   char(amegetvarnamefromui(sname,'YelastoR1@Elastokinematics'));
%%
%% ELECTRO 12 FRONT RIGHT
car_var.WelastoR1_1_FR =   char(amegetvarnamefromui(sname,'WelastoR1_1@Elastokinematics_2'));
car_var.WelastoR1_2_FR =   char(amegetvarnamefromui(sname,'WelastoR1_2@Elastokinematics_2'));
car_var.WelastoR1_3_FR =   char(amegetvarnamefromui(sname,'WelastoR1_3@Elastokinematics_2'));
%%
car_var.THETAelastoR1_1_FR =   char(amegetvarnamefromui(sname,'THETAelastoR1_1@Elastokinematics_2'));
car_var.THETAelastoR1_2_FR =   char(amegetvarnamefromui(sname,'THETAelastoR1_2@Elastokinematics_2'));
car_var.THETAelastoR1_3_FR =   char(amegetvarnamefromui(sname,'THETAelastoR1_3@Elastokinematics_2'));
%%
car_var.VxelastoR1_FR =   char(amegetvarnamefromui(sname,'VxelastoR1@Elastokinematics_2'));
car_var.VyelastoR1_FR =   char(amegetvarnamefromui(sname,'VyelastoR1@Elastokinematics_2'));
car_var.XelastoR1_FR  =   char(amegetvarnamefromui(sname,'XelastoR1@Elastokinematics_2'));
car_var.YelastoR1_FR  =   char(amegetvarnamefromui(sname,'YelastoR1@Elastokinematics_2'));
%%
%% ELECTRO 21 Rear LEFT
car_var.WelastoR1_1_RL =   char(amegetvarnamefromui(sname,'WelastoR1_1@Elastokinematics_2_2'));
car_var.WelastoR1_2_RL =   char(amegetvarnamefromui(sname,'WelastoR1_2@Elastokinematics_2_2'));
car_var.WelastoR1_3_RL =   char(amegetvarnamefromui(sname,'WelastoR1_3@Elastokinematics_2_2'));
%%
car_var.THETAelastoR1_1_RL =   char(amegetvarnamefromui(sname,'THETAelastoR1_1@Elastokinematics_2_2'));
car_var.THETAelastoR1_2_RL =   char(amegetvarnamefromui(sname,'THETAelastoR1_2@Elastokinematics_2_2'));
car_var.THETAelastoR1_3_RL =   char(amegetvarnamefromui(sname,'THETAelastoR1_3@Elastokinematics_2_2'));
%%
car_var.VxelastoR1_RL =   char(amegetvarnamefromui(sname,'VxelastoR1@Elastokinematics_2_2'));
car_var.VyelastoR1_RL =   char(amegetvarnamefromui(sname,'VyelastoR1@Elastokinematics_2_2'));
car_var.XelastoR1_RL  =   char(amegetvarnamefromui(sname,'XelastoR1@Elastokinematics_2_2'));
car_var.YelastoR1_RL  =   char(amegetvarnamefromui(sname,'YelastoR1@Elastokinematics_2_2'));
%%
%% ELECTRO 21 Rear LEFT
car_var.WelastoR1_1_RR =   char(amegetvarnamefromui(sname,'WelastoR1_1@Elastokinematics_3'));
car_var.WelastoR1_2_RR =   char(amegetvarnamefromui(sname,'WelastoR1_2@Elastokinematics_3'));
car_var.WelastoR1_3_RR =   char(amegetvarnamefromui(sname,'WelastoR1_3@Elastokinematics_3'));
%%
car_var.THETAelastoR1_1_RR =   char(amegetvarnamefromui(sname,'THETAelastoR1_1@Elastokinematics_3'));
car_var.THETAelastoR1_2_RR =   char(amegetvarnamefromui(sname,'THETAelastoR1_2@Elastokinematics_3'));
car_var.THETAelastoR1_3_RR =   char(amegetvarnamefromui(sname,'THETAelastoR1_3@Elastokinematics_3'));
%%
car_var.VxelastoR1_RR =   char(amegetvarnamefromui(sname,'VxelastoR1@Elastokinematics_3'));
car_var.VyelastoR1_RR =   char(amegetvarnamefromui(sname,'VyelastoR1@Elastokinematics_3'));
car_var.XelastoR1_RR  =   char(amegetvarnamefromui(sname,'XelastoR1@Elastokinematics_3'));
car_var.YelastoR1_RR  =   char(amegetvarnamefromui(sname,'YelastoR1@Elastokinematics_3'));
%%
