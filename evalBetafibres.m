function [beta_out] = evalBetafibres(ratio, whichbeta)
% 
beta_out = whichbeta*(1-ratio) - whichbeta*ratio;