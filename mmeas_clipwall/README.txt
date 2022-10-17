README
1. Convert to NIFTI in CemrgApp
	1.1 Open CemrgApp 
	1.2 Drag bloodpool and atrial wall
	1.3 On each image's name, right click and save as Nifti
2. Open CemrgApp
	2.2 Click Step3: Segmentation, when asked if you have a segmentation to load say YES
	2.3 Navigate to the working folder and select the segmentation for the bloodpool 
	2.4 Click on Step4: PV Clipper, default values are OK. 
	2.5 Clip the veins (as instructed in document), make sure to indicate correctly each structure
3. Open MATLAB, navigate to the downloaded folder
4. Run Script 'clip_atrial_wall.m':
	4.1 Follow instructions
	4.2 File saved called PVeinsCropped_AWall.nii 
	
A. Optional
If things do not seem to work, it could be that the images are badly oriented. 
The following instructions will guide your to reorienting your images to CemrgApp's 
default (Right-Left, Anterior-Posterior,  RAI)	
A. For of the images (bloodpool and atrial wall) 
	A.1 Open itk-snap and load image (in nrrd) 
	A.2 Click on Tools > Reorient Image... 
	A.3 Check Current Orientation says RAI 
	A.4 In New Orientation, write RAI
	A.5 Click Apply, then Close
	A.6 Save with the formal name: Bloodpool.nii or AtrialWall.nii in the same folder
	A.7 Click Finish
	A.8 Close itk-snap
