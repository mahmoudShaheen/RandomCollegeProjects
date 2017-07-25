function varargout = lab1(varargin)
% LAB1 MATLAB code for lab1.fig
%      LAB1, by itself, creates a new LAB1 or raises the existing
%      singleton*.
%
%      H = LAB1 returns the handle to a new LAB1 or the handle to
%      the existing singleton*.
%
%      LAB1('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in LAB1.M with the given input arguments.
%
%      LAB1('Property','Value',...) creates a new LAB1 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before lab1_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to lab1_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help lab1

% Last Modified by GUIDE v2.5 25-Mar-2017 21:32:14

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @lab1_OpeningFcn, ...
                   'gui_OutputFcn',  @lab1_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before lab1 is made visible.
function lab1_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to lab1 (see VARARGIN)

% Choose default command line output for lab1
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes lab1 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = lab1_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in RadioRR.
function RadioRR_Callback(hObject, eventdata, handles)
% hObject    handle to RadioRR (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of RadioRR

if handles.RadioRR.Value == 1
    cla(handles.axes1) % clear axes 
    handles.Theta0Max.Enable='off'
     handles.Link2.Enable='on'
     handles.changeLableMin.String =" Theta 2 Min "
      handles.changeLableMax.String =" Theta 2 Max "
     
end
   
    
    


% --- Executes on button press in RadioRP.
function RadioRP_Callback(hObject, eventdata, handles)
% hObject    handle to RadioRP (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of RadioRP


if handles.RadioRP.Value == 1
    cla(handles.axes1) % clear axes 
    handles.Theta0Max.Enable='off'
     handles.Link2.Enable='off'
       handles.changeLableMin.String =" Length 2 Min "
      handles.changeLableMax.String =" Length 2 Max "
  
end
   


% --- Executes on button press in RadioRRR.
function RadioRRR_Callback(hObject, eventdata, handles)
% hObject    handle to RadioRRR (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of RadioRRR

if handles.RadioRRR.Value == 1
    cla(handles.axes1) % clear axes 
    handles.Theta0Max.Enable='on'
     handles.Link2.Enable='on'
     
       handles.changeLableMin.String =" Theta 2 Min "
      handles.changeLableMax.String =" Theta 2 Max "
  
end
   


% --- Executes on button press in RadioRRP.
function RadioRRP_Callback(hObject, eventdata, handles)
% hObject    handle to RadioRRP (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of RadioRRP

if handles.RadioRRP.Value == 1
    cla(handles.axes1) % clear axes 
    handles.Theta0Max.Enable='on'
    handles.Link2.Enable='off'
     handles.changeLableMin.String =" Length 2 Min "
      handles.changeLableMax.String =" Length 2 Max "
  
end
   




function Link1_Callback(hObject, eventdata, handles)
% hObject    handle to Link1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Link1 as text
%        str2double(get(hObject,'String')) returns contents of Link1 as a double


% --- Executes during object creation, after setting all properties.
function Link1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Link1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Link2_Callback(hObject, eventdata, handles)
% hObject    handle to Link2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Link2 as text
%        str2double(get(hObject,'String')) returns contents of Link2 as a double


% --- Executes during object creation, after setting all properties.
function Link2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Link2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Theta0Max_Callback(hObject, eventdata, handles)
% hObject    handle to Theta0Max (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Theta0Max as text
%        str2double(get(hObject,'String')) returns contents of Theta0Max as a double


% --- Executes during object creation, after setting all properties.
function Theta0Max_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Theta0Max (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Theta1Min_Callback(hObject, eventdata, handles)
% hObject    handle to Theta1Min (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Theta1Min as text
%        str2double(get(hObject,'String')) returns contents of Theta1Min as a double


% --- Executes during object creation, after setting all properties.
function Theta1Min_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Theta1Min (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Theta1Max_Callback(hObject, eventdata, handles)
% hObject    handle to Theta1Max (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Theta1Max as text
%        str2double(get(hObject,'String')) returns contents of Theta1Max as a double


% --- Executes during object creation, after setting all properties.
function Theta1Max_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Theta1Max (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Theta2Min_Callback(hObject, eventdata, handles)
% hObject    handle to Theta2Min (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Theta2Min as text
%        str2double(get(hObject,'String')) returns contents of Theta2Min as a double


% --- Executes during object creation, after setting all properties.
function Theta2Min_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Theta2Min (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Theta2Max_Callback(hObject, eventdata, handles)
% hObject    handle to Theta2Max (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Theta2Max as text
%        str2double(get(hObject,'String')) returns contents of Theta2Max as a double


% --- Executes during object creation, after setting all properties.
function Theta2Max_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Theta2Max (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in DrawButton.
function DrawButton_Callback(hObject, eventdata, handles)
% hObject    handle to DrawButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of DrawButton



  % if choose radio RR 
if handles.RadioRR.Value==1
    
    cla(handles.axes1) % clear axes 
    Drawing_Step=.05; 
    
    L1=str2num(handles.Link1.String); 
    L2=str2num(handles.Link2.String);
    Th1min=pi*str2num(handles.Theta1Min.String)/180;
    Th1max=pi*str2num(handles.Theta1Max.String)/180;
    Th2min=pi*str2num(handles.Theta2Min.String)/180;
    Th2max=pi*str2num(handles.Theta2Max.String)/180; 
    
    
    for count1 =Th1min:Drawing_Step:Th1max
    for count2 =Th2min:Drawing_Step:Th2max
        x=L1*cos(count1)+L2*cos(count1+count2);
            y=L1*sin(count1)+L2*sin(count1+count2); 
            plot(x,y,'*')
            hold on 
    end
    end
end
    


  % if choose radio RP
if handles.RadioRP.Value==1
    
   
     
    cla(handles.axes1) % clear axes 
    Drawing_Step=.05; 
    
    L1=str2num(handles.Link1.String); 
    %L2=str2num(handles.Link2.String);
    
    Th1min=pi*str2num(handles.Theta1Min.String)/180;
    Th1max=pi*str2num(handles.Theta1Max.String)/180;
    
    
    L2min=str2num(handles.Theta2Min.String);
    L2max=str2num(handles.Theta2Max.String); 
 
    
    
    for count1 =Th1min:Drawing_Step:Th1max
    for count2 =L2min:Drawing_Step*10:L2max
        x=L1*cos(count1)+count2;
            y=L1*sin(count1); 
            plot(x,y,'*')
            
            hold on 
    end
    end
    
end 




  % if choose radio RRR 
if handles.RadioRRR.Value==1
    
     cla(handles.axes1) % clear axes 
    Drawing_Step=.05; 
    
   L1=str2num(handles.Link1.String);
   L2=str2num(handles.Link2.String);
   
   Th1min=pi*str2num(handles.Theta1Min.String)/180;
   Th1max=pi*str2num(handles.Theta1Max.String)/180;
   Th2min=pi*str2num(handles.Theta2Min.String)/180;
   Th2max=pi*str2num(handles.Theta2Max.String)/180; 
   
   
   Th0Max=pi*str2num(handles.Theta0Max.String)/180;
  
   for counter0=0:Drawing_Step:Th0Max
       for counter1=Th1min:Drawing_Step:Th1max  
           for counter2=Th2min:Drawing_Step*4:Th2max  
               
               %ElevationAngle = atan(y/x)
              % y=L2*sin(counter1+counter2)+L1*sin(counter1);
               %x=L1*cos(counter1)+L2*cos(counter1+counter2);
               %ElevationAngle=atan(y/x); 
               ElevationAngle=atan((L2*sin(counter1+counter2)+L1*sin(counter1))/(L1*cos(counter1)+L2*cos(counter1+counter2))); 
               r=sqrt(L1^2+L2^2-2*L1*L2*cos(pi-(counter1+counter2))); % transfere spherical to cartisian coordinates 
               [x,y,z]=sph2cart(counter0,ElevationAngle,r);
               plot3(x,y,z,'*') 
               view(45,30)
               hold on 
               grid on
           end
       end
   end
end 



  % if choose radio RRP 
if handles.RadioRRP.Value==1
    
     cla(handles.axes1) % clear axes 
    Drawing_Step=.05; 
    
   L1=str2num(handles.Link1.String);
   %L2=str2num(handles.Link2.String);
   
   Th1min=pi*str2num(handles.Theta1Min.String)/180;
   Th1max=pi*str2num(handles.Theta1Max.String)/180;
  
    % the length of L2
    L2min=str2num(handles.Theta2Min.String);
    L2max=str2num(handles.Theta2Max.String); 
   
   Th0Max=pi*str2num(handles.Theta0Max.String)/180;
  
   for counter0=0:Drawing_Step:Th0Max
       for counter1=Th1min:Drawing_Step:Th1max  
           for counter2=L2min:Drawing_Step*10:L2max  
               
               %ElevationAngle = atan(y/x)
               ey=L1*sin(counter1);
               ex=L1*cos(counter1)+counter2;
               ElevationAngle=atan(ey/ex); 
               
               r=sqrt(L1^2+counter2^2-2*L1*counter2*cos(pi-counter1)); % transfere spherical to cartisian coordinates 
               [x,y,z]=sph2cart(counter0,ElevationAngle,r);
               plot3(x,y,z,'*') 
               hold on 
               grid on
           end
       end
   end
end 
