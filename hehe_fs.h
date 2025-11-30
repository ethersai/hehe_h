#ifndef HEHe_FS_H_
#define HEHe_FS_H_






#endif/*HEHe_FS_H_*/

// Good approach - figure out the design first!
// Common file utility API patterns:
// Directory operations:
//
// List/iterate files in a directory
// Create directory (with optional parent creation)
// Remove directory (empty vs recursive)
// Check if directory exists
//
// File operations:
//
// Copy file
// Move/rename file
// Delete file
// Check if file exists
// Get file size
// Get file timestamps (created, modified, accessed)
//
// Path manipulation:
//
// Join path components ("dir" + "file.txt" → "dir/file.txt")
// Get file extension
// Get filename without path
// Get directory from full path
// Normalize path (resolve . and ..)
//
// File info/metadata:
//
// Is it a file or directory?
// Is it readable/writable/executable?
// Get file permissions/attributes
//
// The tricky design questions you'll face:
//
// Path separators - Do you normalize everything to / internally? Store platform-specific? Both work, pick one.
// Error handling - Return bool? Error codes? Set errno? Each platform has different error reporting.
// Encoding - Windows uses UTF-16 internally, Linux uses UTF-8. Do you expose wide char versions?
// Buffers - Who allocates them? Caller provides buffer, or you allocate and they free?
//
// Most single-header libraries go with: simple return codes (0 success, -1 fail), caller-provided buffers, UTF-8 strings (convert to wide on Windows internally), and forward slashes normalized internally.
