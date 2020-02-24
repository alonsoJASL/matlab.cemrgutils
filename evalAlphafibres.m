function [alpha_out] = evalAlphafibres(ratio, whichAlpha)
% 
alpha_out = whichAlpha*(1-ratio) - whichAlpha*ratio;

    