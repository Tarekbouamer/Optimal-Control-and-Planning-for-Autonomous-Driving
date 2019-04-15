function [ weights ] = setNodeWeights( nodes, radius, addedNodeId)


% N = length([nodes.x]);
% num = 20;
% if  N < num
%     num = N;
% end
% weights = nodes.weight;
% 
% A = zeros(2,N);
% A(1,:) = [nodes.weight];
% A(2,:) = [1:1:N];
% [~,idx]=sort(A(1,:));
% A = A(:,idx(1:num));
% 
% 
% 
% for i=1:num
%     idx = rangesearch([nodes.x nodes.y],[nodes.x(A(2,i)) nodes.y(A(2,i))],radius);
%     if A(2,i) ~= 1
%         weights(A(2,i)) = length(idx{1});
%     end
% end


weights = nodes.weight;
ids = rangesearch([nodes.x nodes.y],[nodes.x(addedNodeId) nodes.y(addedNodeId)],radius);
weights(addedNodeId) = length(ids{1});
for i=1:length(ids{1})
    idx = rangesearch([nodes.x nodes.y],[nodes.x(ids{1}(i)) nodes.y(ids{1}(i))],radius);
    weights(ids{1}(i)) = length(idx{1});
end

if length(weights) > 50
    weights(1) = 50;
end

end

