function m = io_readCARPMesh(varargin)
% read a carp mesh and convert it to a structure
% node indices in each Element field start from 1 (in the original file they start from 0)
% usage: Mesh=io_readCARPMesh(carpmeshsuffix)
% input: carpmeshsuffix the suffix of the carp mesh (with the path)
% output: Mesh (Mesh.Pts, Mesh.Tri,...)
fileName = varargin{1};
file = fopen( [fileName,'.pts'], 'rt' );
if ~strcmp(varargin{nargin},'mute')
    disp('Read Nodes');
end
nNod = fscanf( file, '%d', 1 );
m.Pts = fscanf( file, '%f %f %f', [3, nNod] )';
clear('nNod');
file = fopen( [fileName,'.elem'], 'rt' );
if ~strcmp(varargin{nargin},'mute')
    disp('Read Elements');
end
Nel= fscanf( file, '%d', 1 );
%pre-allocating
%Triangles
Tri=-1.0*ones(Nel,4);
counterTri=0;
%TetraHedra
Tet=-1.0*ones(Nel,5);
counterTet=0;
%Quadrilaterals
Quad = -1.0*ones(Nel,5);
counterQuad=0;
%Hexahedra
Hex= -1.0*ones(Nel,9);
counterHex=0;
%Edges (connetions)
Edg = -1.0*ones(Nel,3);
counterEdg=0;
%pyramids
Pyr = -1.0*ones(Nel,6);
counterPyr=0;
%prisms
Pri = -1.0*ones(Nel,7);
counterPri=0;
while (~feof( file ))
     elType=fscanf(file,'%s',1);
     elType = strtrim(elType);
    switch (elType)
        case 'Tt' %Tetra
            counterTet=counterTet+1;
            data=fscanf(file,'%d %d %d %d %d',[1,5]);
            Tet(counterTet,:)=data;
            clear('data');
        case 'Tr' %Triangle
            counterTri=counterTri+1;
            data=fscanf(file,'%d %d %d %d',[1,4]);
            Tri(counterTri,:)=data;
            clear('data');
        case 'Qd' %quadrilateral
            counterQuad=counterQuad+1;
            data=fscanf(file,'%d %d %d %d %d',[1,5]);
            Quad(counterQuad,:)=data;
            clear('data');
        case 'Hx' %Hexaedra
            counterHex=counterHex+1;
            data=fscanf(file,'%d %d %d %d %d %d %d %d %d',[1,9]);
            Hex(counterHex,:)=data;
            clear('data');
        case 'Cx' %Edges
            counterEdg=counterEdg+1;
            data=fscanf(file,'%d %d %d',[1,3]);
            Edg(counterEdg,:)=data;
            clear('data');
        case 'Py' %Pyramids
            counterPyr=counterPyr+1;
            data=fscanf(file,'%d %d %d %d %d %d',[1,6]);
            Pyr(counterPyr,:)=data;
            clear('data');
        case 'Pr' %Prisms
            counterPri=counterPri+1;
            data=fscanf(file,'%d %d %d %d %d %d %d',[1,7]);
            Pri(counterPri,:)=data;
            clear('data');
    end
end
fclose( file );
if(counterTet>0)
    Tet(:,1:4)=Tet(:,1:4)+1;
    m.Tet=Tet(1:counterTet,:);
end
clear('Tet','counterTet');
if(counterHex>0)
    Hex(:,1:8)=Hex(:,1:8)+1;
    m.Hex=Hex(1:counterHex,:);
end
clear('Hex','counterHex');
if(counterTri>0)
    Tri(:,1:3)=Tri(:,1:3)+1;
    m.Tri=Tri(1:counterTri,:);
end
clear('Tri','counterTri');
if(counterQuad>0)
    Quad(:,1:4)=Quad(:,1:4)+1;
    m.Quad=Quad(1:counterQuad,:);
end
clear('Quad','counterQuad');
if(counterEdg>0)
  Edg(:,1:2)=Edg(:,1:2)+1;
  m.Edg=Edg(1:counterEdg,:);
end
clear('Edg','counterEdg');
if(counterPyr>0)
  Pyr(:,1:5)=Pyr(:,1:5)+1;
  m.Pyr=Pyr(1:counterPyr,:);
end
clear('Pyr','counterPyr');
if(counterPri>0)
  Pri(:,1:5)=Pri(:,1:6)+1;
  m.Pri=Pri(1:counterPri,:);
end
clear('Pri','counterPri');