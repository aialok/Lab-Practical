# Social Media Network ER Diagram Documentation

## Entities

1. **User**: The central entity representing a user of the social media network.
   - Attributes: user_id, user_name, user_email, user_phone, user_address

2. **Login**: Represents user authentication information.
   - Attributes: login_username, login_password

3. **Roles**: Represents different roles a user can have in the system.
   - Attributes: role_id, role_name, role_desc

4. **Permission**: Represents access rights within the system.
   - Attributes: perm_id, perm_name

5. **Friends**: Represents the friends of a user.
   - Attributes: friend_id, friend_name, friend_username

6. **Photos**: Represents photos uploaded by users.
   - Attributes: photo_id, photo_name, photo_desc, photo_size

7. **Post**: Represents user posts.
   - Attributes: post_id, post_desc, post_type

8. **Shares**: Represents content shared by users.
   - Attributes: share_id, share_name, share_desc, share_type

## Relationships

1. **User-Login**: One-to-One relationship. Each user has one login credential.

2. **User-Roles**: Many-to-Many relationship. Users can have multiple roles, and roles can be assigned to multiple users.

3. **Roles-Permission**: Many-to-Many relationship. Roles can have multiple permissions, and permissions can be assigned to multiple roles.

4. **User-Friends**: One-to-Many relationship. A user can have multiple friends.

5. **User-Photos**: One-to-Many relationship. A user can upload multiple photos.

6. **User-Post**: One-to-Many relationship. A user can create multiple posts.

7. **User-Shares**: One-to-Many relationship. A user can share multiple items.

## Key Observations

1. The diagram uses the crow's foot notation to represent cardinality in relationships.

2. The "Has" relationship between User and Roles suggests that users are assigned roles directly.

3. The "Manage" relationship connecting User, Friends, Photos, Post, and Shares indicates that users manage these entities.

4. The diagram doesn't show explicit foreign key relationships, but they are implied by the connections between entities.

5. There's no separate entity for comments or likes, which are common features in social media platforms.

6. The diagram doesn't show timestamps for created or updated records, which might be useful for auditing and sorting content.

## Potential Improvements

1. Add a Comments entity to allow users to comment on posts and photos.
2. Include a Likes entity to represent user interactions with posts and photos.
3. Add timestamp attributes (created_at, updated_at) to relevant entities for better data management.
4. Consider adding a Messages entity for private communication between users.
5. Include a Profile entity to store additional user information separate from the main User entity.

This ER diagram provides a solid foundation for a basic social media network database structure, covering essential features like user management, content creation, and sharing.
