function [Y, r] = autofocus(U, lb, ub)
    r = lb;
    errs = zeros(ub);
    for i = lb:ub
        curY = focus(U, i);
        errs(i) = evalfocus(curY);
        
        figure
        imshow(scale2im(curY))
        title(i)
        
        if errs(i) < errs(r)
            r = i;
        end
    end
    
    figure
    semilogy(errs)
    
    Y = focus(U, r);
end