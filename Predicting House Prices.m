a=str2num(input("","s"));
n=a(1);
m=a(end);
X=zeros(m,n);
y=zeros(m,1);
for i=1:m
    a=str2num(input("","s"));
    X(i,:)=a(1,1:n);
    y(i,1)=a(end);
end   
m = length(y); % number of training examples
X = [ones(m, 1) X]; % Add a column of ones to x
theta = zeros(3, 1); % initialize fitting parameters

theta = pinv(X'*X)*X'*y;

a=str2num(input("","s"));
k=a;
for i=1:k
    a=str2num(input("","s"));
    a=[ones(1) a];
    disp(a*theta);
end

